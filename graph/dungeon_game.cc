/*
 * @Description: leetcode 174
 * @Author: Chiale
 * @Date: 2019-09-14 15:20:18
 * @LastEditTime: 2019-09-14 15:48:11
 */

#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 0x7fffffff

using namespace std;

int m, n;

vector<vector<int> > buf;

int main() {
    int tmp;
    while (cin >> m >> n) {
        buf.clear();
        for (int i = 0; i != m; ++i) {
            vector<int> line;
            for (int j = 0; j != n; ++j) {
                cin >> tmp;
                line.push_back(tmp);
            }
            buf.push_back(line);
        }
        vector<vector<int> > dp(m + 1, vector<int>(n + 1, MAX));
        // 终点是 (m-1, n-1)
        dp[m][n - 1] = dp[m - 1][n] = 1;
        for (int i = m - 1; i>=0; --i) {
            for (int j = n - 1; j>=0; --j) {
                int future = min(dp[i + 1][j], dp[i][j + 1]);
                int need = future - buf[i][j];
                if (need > 0) {
                    dp[i][j] = need;
                } else {
                    dp[i][j] = 1;
                }
            }
        }
        cout << dp[0][0] << endl;
    }
}
