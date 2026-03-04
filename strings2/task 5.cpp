//task 5

#include <iostream>
#include <string>

using namespace std;

int main() {
    string text, target, replacement;

    cout << "Enter string: ";
    getline(cin, text);
    cout << "What we're searching for?: ";
    cin >> target;
    cout << "Change for what?: ";
    cin >> replacement;

    size_t pos = text.find(target);

    while (pos != string::npos) {
        text.replace(pos, target.length(), replacement);
        pos = text.find(target, pos + replacement.length());
    }

    cout << "Updated string: " << text << endl;

    return 0;
}