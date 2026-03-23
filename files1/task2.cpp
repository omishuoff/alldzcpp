#include <iostream>
#include <fstream>
#include <string> // на всякий випадок додаю, не дуже впевнений

using namespace std;

int main() {
    string filename;
    cin >> filename;

    ifstream file(filename);

    if (!file.is_open()) {
        cout << "Error opening file" << endl;
        return 1;
    }

    string line;
    while (getline(file, line)) {
        cout << line << endl;
    }

    file.close();
    return 0;
}