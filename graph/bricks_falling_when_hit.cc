/*
 * @Description: leetcode 803
 * @Author: Chiale
 * @Date: 2019-09-14 14:43:56
 * @LastEditTime: 2019-09-14 14:43:59
 */

#include <vector>
#include <iostream>

using namespace std;

int m, n;
vector<vector<bool> > grid;

struct DisjointSet {
    vector<int> sets;
    DisjointSet(int num) {
        sets = vector<int>(num, -1);
    }

    int Find(int x) {
        if (sets[x] < 0) return x;
        return sets[x] = Find(sets[x]);
    }

    void Union(int i, int j) {
        int r1 = Find(i);
        int r2 = Find(j);
        if (r1 == r2) return;
        int newSize = sets[r1] + sets[r2];
        if (sets[r1] < sets[r2]) {
            sets[r1] = newSize;
            sets[r2] = r1;
        } else {
            sets[r2] = newSize;
            sets[r1] = r2;
        }
    }

    int getNum(int x) {
        return -sets[Find(x)];
    }
};

int hitBricks(int x, int y) {
    grid[x][y] = false;
    // the last node is the roof node
    DisjointSet ds(m * n + 1);
    for (int i = 0; i != n; ++i) {
        if (grid[0][i]) {
            ds.Union(i, m * n);
        }
    }
    for (int i = 1; i != m; ++i) {
        for (int j = 0; j != n; ++j) {
            if (grid[i][j]) {
                // uppper
                if (grid[i - 1][j]) {
                    ds.Union(i * n + j, (i - 1) * n + j);
                }
                // left
                if (j != 0 && grid[i][j - 1]) {
                    ds.Union(i * n + j, i * n + j - 1);
                }
            }
        }
    }

    // put back (x,y)
    int prev = ds.getNum(m * n);
    // connect arround
    if (x + 1 < m && grid[x + 1][y]) {
        ds.Union((x + 1) * n + y, x * n + y);
    }
    if (x - 1 >= 0 && grid[x - 1][y]) {
        ds.Union((x - 1) * n + y, x * n + y);
    }
    if (y + 1 < n && grid[x][y + 1]) {
        ds.Union(x * n + y + 1, x * n + y);
    }
    if (y - 1 >= 0 && grid[x][y - 1]) {
        ds.Union(x * n + y - 1, x * n + y);
    }
    return ds.getNum(m * n) - prev - 1;
}

int main() {
    while (cin >> m >> n) {
        bool tmp;
        vector<bool> line;
        line.reserve(n);
        grid.clear();

        for (int i = 0; i != m; ++i) {
            line.clear();
            for (int j = 0; j != n; ++j) {
                cin >> tmp;
                line.push_back(tmp);
            }
            grid.push_back(line);
        }

        int x, y;

        cin >> x >> y;
        cout << hitBricks(x, y) << endl;
    }
}
