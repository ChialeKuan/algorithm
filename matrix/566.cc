/*
 * @Description: reshape the matrix
 * @Author: Chiale
 * @Date: 2022-03-29 21:58:02
 * @LastEditTime: 2022-03-29 22:22:35
 */

#include "matrix.h"
#include <ctime>

using namespace std;

vector<vector<int>> matrixReshape(vector<vector<int>> &matrix, int r, int c) {
    if (matrix.empty() || matrix[0].empty() ||
        r * c != matrix.size() * matrix[0].size())
        return matrix;
    vector<vector<int>> result(r, vector<int>(c, 0));
    int row = 0, col = 0;
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[0].size(); ++j) {
            result[row][col] = matrix[i][j];
            col++;
            if (col == c) {
                row++;
                col = 0;
            }
        }
    }
    return result;
}

int main(int argc, char const *argv[]) {
    int m, n, r, c;
    int tmp;
    vector<vector<int>> matrix;
    vector<int> row;
    auto start = clock();
    while (cin >> m >> n >> r >> c) {
        matrix.clear();
        row.reserve(n);
        matrix.reserve(m);
        for (auto i = 0; i != m; i++) {
            row.clear();
            for (auto j = 0; j != n; j++) {
                cin >> tmp;
                row.push_back(tmp);
            }
            matrix.push_back(row);
        }
        cout << "before reshape:" << endl;
        printMatrix(matrix);
        auto result = matrixReshape(matrix, r, c);
        cout << "after reshape:" << endl;
        printMatrix(result);
    }
    auto end = clock();
    cout << "time cost: " << (end - start) << "ms" << endl;
    return 0;
}
