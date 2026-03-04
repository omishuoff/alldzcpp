//task 3

#include <iostream>
#include <string>

using namespace std;

int main() {
    string text;
    char target;
    int count = 0;

    cout << "Enter string: ";
    getline(cin, text);

    cout << "Enter symb to find it: ";
    cin >> target;

    for (int i = 0; i < text.length(); i++) {
        if (text[i] == target) {
            count++;
        }
    }

    if (count > 0) {
        cout << "Symb '" << target << "' here " << count << " times." << endl;
    }
    else {
        cout << "Here is no symb like this." << endl;
    }

    return 0;
}