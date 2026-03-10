//тут я хотів зробити менюшку через свіч для вибору дії
//але із за багу не вийшло, тому висилаю такий варіант

#include <iostream>

using namespace std;

struct Student {
    string surname;
    string group;
    int grades[5];
};

Student* resizeArray(Student* oldArray, int oldSize, int newSize) {
    Student* newArray = new Student[newSize];
    for (int i = 0; i < (oldSize < newSize ? oldSize : newSize); i++) {
        newArray[i] = oldArray[i];
    }
    delete[] oldArray;
    return newArray;
}

int main() {
    int size = 2;
    Student* students = new Student[size];

    students[0] = { "Ivanov", "A-1", {5, 5, 5, 4, 5} };
    students[1] = { "Petrov", "A-1", {2, 3, 2, 5, 3} };

    students = resizeArray(students, size, 3);
    size = 3;
    students[2] = { "Sidorov", "B-2", {4, 4, 4, 4, 4} };

    cout << "Excellent:" << endl;
    for (int i = 0; i < size; i++) {
        int c5 = 0;
        for (int j = 0; j < 5; j++) if (students[i].grades[j] == 5) c5++;
        if (c5 >= 4) cout << students[i].surname << endl;
    }

    cout << "\nLow performers:" << endl;
    for (int i = 0; i < size; i++) {
        int cBad = 0;
        for (int j = 0; j < 5; j++) {
            if (students[i].grades[j] == 2 || students[i].grades[j] == 3) cBad++;
        }
        if (cBad >= 3) cout << students[i].surname << endl;
    }

    delete[] students;
    return 0;
}