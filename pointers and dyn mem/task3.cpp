#include <iostream>

using namespace std;

int* insertBlock(int* arr, int& size, int index, const int* block, int blockSize) {
    if (index < 0 || index > size) {
        return arr;
    }

    int newSize = size + blockSize;
    int* newArr = new int[newSize];

    for (int i = 0; i < index; ++i) {
        newArr[i] = arr[i];
    }

    for (int i = 0; i < blockSize; ++i) {
        newArr[index + i] = block[i];
    }

    for (int i = index; i < size; ++i) {
        newArr[i + blockSize] = arr[i];
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

    int blockSize;
    cin >> blockSize;

    int* block = new int[blockSize];
    for (int i = 0; i < blockSize; ++i) {
        cin >> block[i];
    }

    int index;
    cin >> index;

    arr = insertBlock(arr, size, index, block, blockSize);

    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr;
    delete[] block;

    return 0;
}