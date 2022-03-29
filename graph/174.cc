/*
 * @Description: dungeon game
 * @Author: Chiale
 * @Date: 2019-09-14 15:20:18
 * @LastEditTime: 2022-03-29 17:44:25
 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int printMatrix(vector<vector<int>> &matrix) {
    for (auto i = 0; i != matrix.size(); ++i) {
        for (auto j = 0; j != matrix[0].size(); ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

int dungeonGame_v1(vector<vector<int>> &dungeon) {
    const int m = dungeon.size();
    const int n = dungeon[0].size();
    vector<vector<int>> buf(m, vector<int>(n, 0));
    buf[m - 1][n - 1] = 1 + max(0, -dungeon[m - 1][n - 1]);
    for (auto i = m - 2; i >= 0; i--) {
        buf[i][n - 1] = max(1, buf[i + 1][n - 1] - dungeon[i][n - 1]);
    }
    for (auto j = n - 2; j >= 0; j--) {
        buf[m - 1][j] = max(1, buf[m - 1][j + 1] - dungeon[m - 1][j]);
    }
    for (auto i = m - 2; i >= 0; i--) {
        for (auto j = n - 2; j >= 0; j--) {
            auto lower_nb = min(buf[i + 1][j], buf[i][j + 1]);
            buf[i][j] = max(1, lower_nb - dungeon[i][j]);
        }
    }
    // printMatrix(buf);
    return buf[0][0];
}

// reduce the space complexity from O(m*n) to O(n)
int dungeonGame_v2(vector<vector<int>> &dungeon) {
    const int m = dungeon.size();
    const int n = dungeon[0].size();
    vector<int> buf(n + 1, INT_MAX);
    // the initial value of the last element of the buf is 1
    buf[n - 1] = 1;
    for (auto x = m - 1; x >= 0; x--) {
        for (auto y = n - 1; y >= 0; y--) {
            buf[y] = max(1, min(buf[y], buf[y + 1]) - dungeon[x][y]);
        }
    }
    return buf[0];
}

int main() {
    int tmp;
    int m, n;
    vector<vector<int>> dungeon;
    while (cin >> m >> n) {
        dungeon.clear();
        for (auto i = 0; i != m; i++) {
            vector<int> line;
            for (int j = 0; j != n; j++) {
                cin >> tmp;
                line.push_back(tmp);
            }
            dungeon.push_back(line);
        }
        cout << dungeonGame_v2(dungeon) << endl;
    }
}
