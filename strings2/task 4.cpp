//task 4

#include <iostream>
#include <string>

using namespace std;

int main() {
    string line;
    cout << "Ebter string: ";
    getline(cin, line);

    string longest = "";
    string currentWord = "";
    string tempLine = line + " ";

    for (int i = 0; i < tempLine.length(); i++) {
        if (tempLine[i] != ' ') {
            currentWord += tempLine[i];
        }
        else {
            if (currentWord.length() > longest.length()) {
                longest = currentWord;
            }
            currentWord = "";
        }
    }

    cout << "Longest word: " << longest << endl;

    return 0;
}