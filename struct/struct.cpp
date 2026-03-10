#include <iostream>

using namespace std;

typedef struct {
    string surname;
    char gender;
    double avgGrade;
} Student;

int main() {
    int n = 4;
    Student group[] = {
        {"Yudin", 'M', 4.5},
        {"Beker", 'F', 4.8},
        {"Mavridi", 'M', 3.9},
        {"Andreeva", 'F', 4.2}
    };

    double sumM = 0, sumF = 0;
    int countM = 0, countF = 0;

    for (int i = 0; i < n; i++) {
        if (group[i].gender == 'M') {
            sumM += group[i].avgGrade;
            countM++;
        }
        else {
            sumF += group[i].avgGrade;
            countF++;
        }
    }

    double avgM = (countM > 0) ? sumM / countM : 0;
    double avgF = (countF > 0) ? sumF / countF : 0;

    cout << "Average M: " << avgM << endl;
    cout << "Average F: " << avgF << endl;

    if (avgM > avgF)
        cout << "Boys are better" << endl;
    else if (avgF > avgM)
        cout << "Girls are better" << endl;
    else
        cout << "Equal" << endl;

    return 0;
}