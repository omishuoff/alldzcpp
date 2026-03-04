#include <iostream>
using namespace std;

int main() {
    const int SIZE = 6;
    int source[SIZE] = { 1, 2, 3, 4, 5, 6 };
    int destination[SIZE];

    int* pSrc = source + SIZE - 1;
    int* pDest = destination;

    for (int i = 0; i < SIZE; i++) {
        *pDest = *pSrc;
        pSrc--;
        pDest++;
    }

    cout << "Source: ";
    for (int i = 0; i < SIZE; i++) cout << source[i] << " ";

    cout << "\nDestination (reversed copy): ";
    for (int i = 0; i < SIZE; i++) cout << destination[i] << " ";

    return 0;
}