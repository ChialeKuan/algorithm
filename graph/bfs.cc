/*
 * @Description: get out before time t
 * @Author: Chiale
 * @Date: 2019-09-07 09:35:55
 * @LastEditTime: 2019-09-07 18:49:14
 */

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct node {
  int x, y, z;
  int t;
};

bool mark[50][50][50];
int maze[50][50][50];
int to[6][3] = {1, 0, 0, -1, 0, 0, 0, 1, 0, 0, -1, 0, 0, 0, 1, 0, 0, -1};

int BFS(int a, int b, int c) {
  int x, y, z;
  node n, tmp;
  queue<node> q;

  mark[0][0][0] = true;
  n.x = 0;
  n.y = 0;
  n.z = 0;
  n.t = 0;
  q.push(n);
  while (!q.empty()) {
    n = q.front();
    q.pop();
    for (int i = 0; i != 6; ++i) {
      x = n.x + to[i][0];
      y = n.y + to[i][1];
      z = n.z + to[i][2];
      if (x < 0 || y < 0 || z < 0 || x >= a || y >= b || z >= c) continue;
      if (maze[x][y][z]) continue;
      if (mark[x][y][z]) continue;
      tmp.x = x;
      tmp.y = y;
      tmp.z = z;
      tmp.t = n.t + 1;
      q.push(tmp);
      mark[x][y][z] = true;
      if (x == a - 1 && y == b - 1 && z == c - 1) return tmp.t;
    }
  }
  return -1;
}

int main(int argc, const char* argv[]) {
  int a, b, c, t;

  while (cin >> a >> b >> c >> t) {
    for (int i = 0; i != a; ++i) {
      for (int j = 0; j != b; ++j) {
        for (int k = 0; k != c; ++k) {
          cin >> maze[i][j][k];
          mark[i][j][k] = false;
        }
      }
    }
    int ret = BFS(a, b, c);
    if (ret <= t) cout << ret << endl;
  }

  return 0;
}