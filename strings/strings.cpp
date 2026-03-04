//завдання 1

#include <iostream>
using namespace std;

void limitedFunction(bool reset = false) {
    static int counter = 0;

    if (reset) {
        counter = 0;
        cout << "Counter reset." << endl;
        return;
    }

    if (counter < 3) {
        counter++;
        cout << "Call no" << counter << ": Funk succeed." << endl;
    }
    else {
        cout << "So many calls!" << endl;
    }
}

int main() {
    cout << "Test of func w' limit 3:" << endl;
    limitedFunction();
    limitedFunction();
    limitedFunction();
    limitedFunction();

    cout << endl << "Reset of counter: ";
    limitedFunction(true);

    cout << endl << "New test after reset:" << endl;
    limitedFunction();
    limitedFunction();

    return 0;
}