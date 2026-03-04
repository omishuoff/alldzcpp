//task 2

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string students[5];
    cout << "Enter 5 surnames:" << endl;
    for (int i = 0; i < 5; i++) cin >> students[i];

    sort(students, students + 5, greater<string>());

    cout << "\nResult of sort:" << endl;
    for (string s : students) cout << s << endl;
    return 0;
}