#include <iostream>
using namespace std;

int main() {
    const int SIZE = 5;
    int source[SIZE] = { 10, 20, 30, 40, 50 };
    int destination[SIZE];

    int* pSrc = source;
    int* pDest = destination;

    for (int i = 0; i < SIZE; i++) {
        *pDest = *pSrc;
        pSrc++;
        pDest++;
    }

    cout << "Copied array: ";
    for (int i = 0; i < SIZE; i++) cout << destination[i] << " ";

    return 0;
}