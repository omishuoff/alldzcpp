#include <iostream>
using namespace std;

int main() {
    const int SIZE = 5;
    int arr[SIZE] = { 1, 2, 3, 4, 5 };

    int* pStart = arr;
    int* pEnd = arr + SIZE - 1;

    while (pStart < pEnd) {
        int temp = *pStart;
        *pStart = *pEnd;
        *pEnd = temp;

        pStart++;
        pEnd--;
    }

    cout << "Reversed array: ";
    for (int i = 0; i < SIZE; i++) cout << arr[i] << " ";

    return 0;
}