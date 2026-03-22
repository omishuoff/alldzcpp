#include <iostream>

using namespace std;

bool contains(int* arr, int size, int value) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == value) {
            return true;
        }
    }
    return false;
}

int main() {
    int M, N;
    cin >> M >> N;

    int* A = new int[M];
    for (int i = 0; i < M; ++i) {
        cin >> A[i];
    }

    int* B = new int[N];
    for (int i = 0; i < N; ++i) {
        cin >> B[i];
    }

    int* temp = new int[M + N];
    int k = 0;

    for (int i = 0; i < M; ++i) {
        if (!contains(B, N, A[i]) && !contains(temp, k, A[i])) {
            temp[k++] = A[i];
        }
    }

    for (int i = 0; i < N; ++i) {
        if (!contains(A, M, B[i]) && !contains(temp, k, B[i])) {
            temp[k++] = B[i];
        }
    }

    int* result = new int[k];
    for (int i = 0; i < k; ++i) {
        result[i] = temp[i];
    }

    for (int i = 0; i < k; ++i) {
        cout << result[i] << " ";
    }
    cout << endl;

    delete[] A;
    delete[] B;
    delete[] temp;
    delete[] result;

    return 0;
}