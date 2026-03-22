#include <iostream>
#include <vector>

using namespace std;

void flattenMatrix(const vector<vector<int>>& matrix, vector<int>& result) {
    result.clear();
    for (const auto& row : matrix) {
        for (int val : row) {
            result.push_back(val);
        }
    }
}

int main() {
    int rows, cols;
    cin >> rows >> cols;

    vector<vector<int>> matrix(rows, vector<int>(cols));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cin >> matrix[i][j];
        }
    }

    vector<int> flat;
    flattenMatrix(matrix, flat);

    for (int x : flat) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}