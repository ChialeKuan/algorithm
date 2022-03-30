/*
 * @Description: 
 * @Author: Chiale
 * @Date: 2022-03-29 22:06:13
 * @LastEditTime: 2022-03-29 22:13:32
 */

#include "matrix.h"

int printMatrix(const vector<vector<int>> &matrix) {
    if (matrix.empty() or matrix[0].empty()) return 0;
    int row = 0, col = 0;
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[0].size(); j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}