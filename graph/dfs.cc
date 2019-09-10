/*
 * @Description: from s to d in exactly t seconds
 * @Author: Chiale
 * @Date: 2019-09-07 18:33:53
 * @LastEditTime: 2019-09-07 19:21:24
 */

#include <iostream>
#define MAX 10

using namespace std;

int n, m, t;
char maze[MAX][MAX];
int go[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};
bool ans;

void DFS(int x, int y, int time) {
  int nx, ny;
  for (int i = 0; i != 4; ++i) {
    // move
    nx = x + go[i][0];
    ny = y + go[i][1];
    // test
    if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
    if (maze[nx][ny] == '1') continue;
    if (maze[nx][ny] == 'D') {
      // next second get to the final
      if (time + 1 == t) {
        ans = true;
        return;
      } else
        continue;
    }
    // no backstep, gonna block
    maze[nx][ny] = '1';
    // recursion
    DFS(nx, ny, time + 1);
    // found and exit
    if (ans) return;
    // timeout
    if (time >= t) return;
    // restore
    maze[nx][ny] = '0';
  }
}

int main(int argc, const char *argv[]) {
  while (cin >> n >> m >> t) {
    ans = false;

    for (int i = 0; i != n; ++i) {
      for (int j = 0; j != m; ++j) {
        cin >> maze[i][j];
      }
    }

    for (int i = 0; i != n; ++i) {
      for (int j = 0; j != m; ++j) {
        if (maze[i][j] == 'S') {
          maze[i][j] = '1';
          DFS(i, j, 0);
          break;
        }
      }
    }
    if (ans) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  }
  return 0;
}
