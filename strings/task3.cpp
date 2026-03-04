//завдання 3,4

#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

int main() {
    char word[100];
    cout << "Enter ur word: ";
    cin >> word;

    int letters = 0, digits = 0, others = 0;
    for (int i = 0; i < strlen(word); i++) {
        if (isalpha(word[i])) letters++;
        else if (isdigit(word[i])) digits++;
        else others++;
    }

    cout << "Letters: " << letters << ", Digits: " << digits << ", Other: " << others << endl;

    char target;
    cout << "Enter symb for search: ";
    cin >> target;

    int count = 0;
    for (int i = 0; i < strlen(word); i++) {
        if (word[i] == target) count++;
    }

    if (count > 0) cout << "Symb found " << count << " times." << endl;
    else cout << "No symb here." << endl;

    return 0;
}