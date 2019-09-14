/*
 * @Description: leetcode 741
 * @Author: Chiale
 * @Date: 2019-09-14 16:27:43
 * @LastEditTime: 2019-09-14 16:30:54
 */

#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 50
using namespace std;

int m, n;

vector<vector<int> > grid;
int dp[2 * MAX][MAX][MAX];

int main() {
    int tmp;
    while (cin >> m >> n) {
        grid.clear();
        for (int i = 0; i != m; ++i) {
            vector<int> line;
            for (int j = 0; j != n; ++j) {
                cin >> tmp;
                line.push_back(tmp);
            }
            grid.push_back(line);
        }
        // i the total step
        // j y of the first person
        // k y of the second person
        dp[0][0][0] = grid[0][0];
        for (int i = 1; i < m + n - 1; ++i) {
            for (int j = 0; j < min(i + 1, m); ++j) {
                if (i - j >= n) continue;
                for (int k = 0; k < min(i + 1, m); ++k) {
                    if (i - k >= n) continue;
                    if (grid[j][i - j] < 0 || grid[k][i - k] < 0) continue;
                    // note -1 is not walkable
                    int previous = -1;
                    // not border
                    if (j > 0 && i - k > 0) previous = max(previous, dp[i - 1][j - 1][k]);
                    if (k > 0 && i - j > 0) previous = max(previous, dp[i - 1][j][k - 1]);
                    if (j > 0 && k > 0) previous = max(previous, dp[i - 1][j - 1][k - 1]);
                    if (i - j > 0 && i - k > 0) previous = max(previous, dp[i - 1][j ][k ]);
                    if (previous >= 0) {
                        dp[i][j][k] = previous + grid[j][i - j];
                        if (j != k) dp[i][j][k] += grid[i][i - k];
                    } else {
                        dp[i][j][k] = -1;
                    }
                }
            }
        }
        cout << max(0, dp[m + n - 2][m - 1][m - 1]) << endl;
    }
}
