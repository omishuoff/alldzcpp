#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int main() {
    string filename;
    cin >> filename;

    ifstream file(filename);

    if (!file.is_open()) {
        cout << "Error opening file" << endl;
        return 1;
    }

    int lineCount = 0;
    int wordCount = 0;
    string line;

    while (getline(file, line)) {
        lineCount++;
        stringstream ss(line);
        string word;
        while (ss >> word) {
            wordCount++;
        }
    }

    cout << "Lines: " << lineCount << endl;
    cout << "Words: " << wordCount << endl;

    file.close();
    return 0;
}