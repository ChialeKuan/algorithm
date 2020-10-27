/*
 * @Description: leetcode 407
 * @Author: Chiale
 * @Date: 2019-09-14 09:27:34
 * @LastEditTime: 2020-10-27 14:14:36
 */

// BFS
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

#define NINF 0x80000000

using namespace std;

int trapRainWater(vector<vector<int> >& grid) {
    if (grid.empty()) {
        return 0;
    }
    priority_queue<pair<int, int>, vector<pair<int, int> >,
                   greater<pair<int, int> > >
        q;
    auto m = grid.size();
    auto n = grid[0].size();
    vector<vector<bool> > visited(m, vector<bool>(n, false));
    int ans = 0;
    int maxHeight = NINF;
    // border
    for (int i = 0; i != m; ++i) {
        for (int j = 0; j != n; ++j) {
            if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
                q.push(make_pair(grid[i][j], i * n + j));
                visited[i][j] = true;
            }
        }
    }
    vector<vector<int> > dir{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    while (!q.empty()) {
        auto val = q.top();
        q.pop();
        int height = val.first;
        int x = val.second / n;
        int y = val.second % n;
        maxHeight = max(maxHeight, height);
        for (auto d : dir) {
            int x2 = x + d[0];
            int y2 = y + d[1];
            if (x2 < 0 || x2 >= m || y2 < 0 || y2 >= n || visited[x2][y2])
                continue;
            visited[x2][y2] = true;
            if (grid[x2][y2] < maxHeight) {
                ans += maxHeight - grid[x2][y2];
            }
            // any way the new land could be the border
            q.push(make_pair(grid[x2][y2], x2 * n + y2));
        }
    }
    return ans;
}

int main() {
    int tmp;
    int m, n;

    while (cin >> m >> n) {
        vector<vector<int> > grid;

        for (int i = 0; i != m; ++i) {
            vector<int> line;
            for (int j = 0; j != n; ++j) {
                cin >> tmp;
                line.push_back(tmp);
            }
            grid.push_back(line);
        }
        cout << trapRainWater(grid) << endl;
    }
}
