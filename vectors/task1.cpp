#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void fillVector(vector<int>& v, int size) {
    for (int i = 0; i < size; ++i) {
        v.push_back(rand() % 21 - 10);
    }
}

void sortAscending(vector<int>& v) {
    sort(v.begin(), v.end());
}

void mergeDescending(const vector<int>& v1, const vector<int>& v2, vector<int>& result) {
    result.clear();
    result.insert(result.end(), v1.begin(), v1.end());
    result.insert(result.end(), v2.begin(), v2.end());
    sort(result.begin(), result.end(), greater<int>());
}

void printVector(const vector<int>& v) {
    for (int x : v) {
        cout << x << " ";
    }
    cout << endl;
}

int main() {
    srand(time(0));
    int size1, size2;
    cin >> size1 >> size2;

    vector<int> A, B, C;

    fillVector(A, size1);
    fillVector(B, size2);

    sortAscending(A);
    sortAscending(B);

    cout << "A: ";
    printVector(A);
    cout << "B: ";
    printVector(B);

    mergeDescending(A, B, C);

    cout << "Result (descending): ";
    printVector(C);

    return 0;
}