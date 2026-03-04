//task6

#include <iostream>
#include <string>

using namespace std;

int main() {
    string word;
    cout << "Enter word to check: ";
    cin >> word;

    bool isPalindrome = true;
    int n = word.length();

    // Йдемо до середини слова
    for (int i = 0; i < n / 2; i++) {
        if (word[i] != word[n - 1 - i]) {
            isPalindrome = false;
            break;
        }
    }

    if (isPalindrome) {
        cout << "its palindrome" << endl;
    }
    else {
        cout << "Its not palindrome" << endl;
    }

    return 0;
}