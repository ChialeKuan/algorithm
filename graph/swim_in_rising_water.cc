/*
 * @Description: leetcode 778
 * @Author: Chiale
 * @Date: 2019-09-14 10:46:21
 * @LastEditTime: 2019-09-14 10:48:27
 */

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Point {
    int x, y;
    int v;
    Point(int x, int y, int v) : x(x), y(y), v(v) {}

    bool operator<(const Point& a) const { return v > a.v; }
};
int swim(vector<vector<int> >& grid) {
    if (grid.empty()) return 0;
    if (grid[0].empty()) return 0;
    priority_queue<Point> q;
    vector<vector<bool> > visited(grid.size(),
                                  vector<bool>(grid[0].size(), false));

    auto m = grid.size();
    auto n = grid[0].size();
    q.push(Point(0, 0, grid[0][0]));
    visited[0][0] = true;
    vector<vector<int> > dirs{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    while (!q.empty()) {
        auto cur = q.top();
        q.pop();
        if (cur.x == m - 1 && cur.y == n - 1) return cur.v;
        for (auto d : dirs) {
            int x2 = cur.x + d[0];
            int y2 = cur.y + d[1];
            if (x2 < 0 || x2 >= m || y2 < 0 || y2 >= n || visited[x2][y2])
                continue;
            visited[x2][y2] = true;
            q.push(Point(x2, y2, max(cur.v, grid[x2][y2])));
        }
    }
    return -1;
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
        cout << swim(grid) << endl;
    }
}
