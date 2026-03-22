#include <iostream>

using namespace std;

int** addColumn(int** matrix, int rows, int& cols, int pos, const int* newCol) {
    if (pos < 0 || pos > cols) {
        return matrix;
    }

    for (int i = 0; i < rows; ++i) {
        int* newRow = new int[cols + 1];

        for (int j = 0; j < pos; ++j) {
            newRow[j] = matrix[i][j];
        }

        newRow[pos] = newCol[i];

        for (int j = pos; j < cols; ++j) {
            newRow[j + 1] = matrix[i][j];
        }

        delete[] matrix[i];
        matrix[i] = newRow;
    }

    cols++;
    return matrix;
}

int main() {
    int rows, cols;
    cin >> rows >> cols;

    int** matrix = new int* [rows];
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new int[cols];
        for (int j = 0; j < cols; ++j) {
            cin >> matrix[i][j];
        }
    }

    int* newCol = new int[rows];
    for (int i = 0; i < rows; ++i) {
        cin >> newCol[i];
    }

    int pos;
    cin >> pos;

    matrix = addColumn(matrix, rows, cols, pos, newCol);

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < rows; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
    delete[] newCol;

    return 0;
}