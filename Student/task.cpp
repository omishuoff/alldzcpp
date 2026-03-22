#include <iostream>

#define GRADES_COUNT 5
#define EXCELLENT_MARK 5
#define FAIL_MARK_LOW 2
#define FAIL_MARK_HIGH 3

using namespace std;

struct Student {
    string surname;
    string group;
    int grades[GRADES_COUNT];
};

void addStudent(Student*& students, int& size) {
    Student* newArray = new Student[size + 1];
    for (int i = 0; i < size; ++i) {
        newArray[i] = students[i];
    }

    cout << "Surname: ";
    cin >> newArray[size].surname;
    cout << "Group: ";
    cin >> newArray[size].group;
    cout << "Enter " << GRADES_COUNT << " grades: ";
    for (int i = 0; i < GRADES_COUNT; ++i) {
        cin >> newArray[size].grades[i];
    }

    delete[] students;
    students = newArray;
    size++;
}

void printExcellent(Student* students, int size) {
    cout << "\nExcellent students (>75% A's):" << endl;
    for (int i = 0; i < size; ++i) {
        int count = 0;
        for (int j = 0; j < GRADES_COUNT; ++j) {
            if (students[i].grades[j] == EXCELLENT_MARK) {
                count++;
            }
        }
        if ((double)count / GRADES_COUNT > 0.75) {
            cout << students[i].surname << " (" << students[i].group << ")" << endl;
        }
    }
}

void printFailing(Student* students, int size) {
    cout << "\nFailing students (>50% 2s and 3s):" << endl;
    for (int i = 0; i < size; ++i) {
        int count = 0;
        for (int j = 0; j < GRADES_COUNT; ++j) {
            if (students[i].grades[j] == FAIL_MARK_LOW || students[i].grades[j] == FAIL_MARK_HIGH) {
                count++;
            }
        }
        if ((double)count / GRADES_COUNT > 0.5) {
            cout << students[i].surname << " (" << students[i].group << ")" << endl;
        }
    }
}

int main() {
    int size = 0;
    Student* students = nullptr;
    int choice;

    do {
        cout << "\n1. Add Student\n2. Show Excellent\n3. Show Failing\n0. Exit\nChoice: ";
        cin >> choice;

        if (choice == 1) {
            addStudent(students, size);
        }
        else if (choice == 2) {
            printExcellent(students, size);
        }
        else if (choice == 3) {
            printFailing(students, size);
        }
    } while (choice != 0);

    delete[] students;
    return 0;
}