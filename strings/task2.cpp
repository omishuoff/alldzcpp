//завдання 2

#include <iostream>
using namespace std;

template <typename T>
T findMax1D(T arr[], int size) {
    T maxVal = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > maxVal) maxVal = arr[i];
    }
    return maxVal;
}

const int COLS = 3;
template <typename T>
T findMax2D(T arr[][COLS], int rows) {
    T maxVal = arr[0][0];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < COLS; j++) {
            if (arr[i][j] > maxVal) maxVal = arr[i][j];
        }
    }
    return maxVal;
}

int main() {
    int arr1D[] = { 10, 55, 23, 89, 4 };
    cout << "Max in 1D: " << findMax1D(arr1D, 5) << endl;

    int arr2D[2][COLS] = { {1, 25, 3}, {44, 5, 12} };
    cout << "Max in 2D: " << findMax2D(arr2D, 2) << endl;

    return 0;
}