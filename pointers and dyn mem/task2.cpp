#include <iostream>

using namespace std;

int* removeEvens(int* arr, int& size) {
    int newSize = 0;
    for (int i = 0; i < size; ++i) {
        if (arr[i] % 2 != 0) {
            newSize++;
        }
    }

    int* newArr = new int[newSize];
    int j = 0;
    for (int i = 0; i < size; ++i) {
        if (arr[i] % 2 != 0) {
            newArr[j++] = arr[i];
        }
    }

    delete[] arr;
    size = newSize;
    return newArr;
}

int main() {
    int size;
    cin >> size;

    int* arr = new int[size];
    for (int i = 0; i < size; ++i) {
        cin >> arr[i];
    }

    arr = removeEvens(arr, size);

    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr;

    return 0;
}