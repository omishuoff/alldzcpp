// task 1

#include <iostream>
#include <string>

using namespace std;

bool isValidIP(string ip) {
    int dots = 0;
    string segment = "";
    string tempIp = ip + ".";

    for (int i = 0; i < tempIp.length(); i++) {
        if (tempIp[i] == '.') {
            dots++;
            if (segment.empty() || segment.length() > 3) return false;
            if (segment.length() > 1 && segment[0] == '0') return false;

            int val = stoi(segment);
            if (val < 0 || val > 255) return false;

            segment = "";
        }
        else {
            if (!isdigit(tempIp[i])) return false;
            segment += tempIp[i];
        }
    }
    return dots == 4; 
}

int main() {
    string ip;
    cout << "Enter IP: ";
    cin >> ip;

    if (isValidIP(ip)) cout << "IP correct" << endl;
    else cout << "IP incorrect" << endl;

    return 0;
}