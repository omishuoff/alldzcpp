#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isValidLength(int length) {
    return length >= 8;
}

void generatePassword(int length, vector<char>& password) {
    string lowers = "abcdefghijklmnopqrstuvwxyz";
    string uppers = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string digits = "0123456789";
    string specials = "!@#$%^&*()_+-=[]{}|";
    string all = lowers + uppers + digits + specials;

    password.clear();
    password.push_back(lowers[rand() % lowers.length()]);
    password.push_back(uppers[rand() % uppers.length()]);
    password.push_back(digits[rand() % digits.length()]);
    password.push_back(specials[rand() % specials.length()]);

    for (int i = 4; i < length; ++i) {
        password.push_back(all[rand() % all.length()]);
    }

    random_shuffle(password.begin(), password.end());
}

void printPassword(const vector<char>& password) {
    for (char c : password) {
        cout << c;
    }
    cout << endl;
}

int main() {
    srand(time(0));
    int length;
    cout << "Enter password length: ";
    cin >> length;

    if (!isValidLength(length)) {
        cout << "Error: minimum length is 8" << endl;
        return 1;
    }

    vector<char> password;
    generatePassword(length, password);

    cout << "Generated password: ";
    printPassword(password);

    return 0;
}