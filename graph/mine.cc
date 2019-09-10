/*
 * @Description: 回溯法
 * @Author: Chiale
 * @Date: 2019-09-07 15:28:17
 * @LastEditTime: 2019-09-07 15:57:58
 */

#include <iostream>
#define MAX 100
using namespace std;

int n, m;
char mine[MAX][MAX];
bool mark[MAX][MAX];

int go[8][2] = {1, 1, 1, -1, -1, 1, -1, -1, 1, 0, 0, 1, -1, 0, 0, -1};

void DFS(int x, int y) {
  int nx, ny;
  for (int i = 0; i != 8; ++i) {
    nx = x + go[i][0];
    ny = y + go[i][1];
    if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
    if (mine[nx][ny] == '*') continue;
    if (mark[nx][ny]) continue;
    mark[nx][ny] = true;
    DFS(nx, ny);
  }
}

int main(int argc, const char* argv[]) {
  while (cin >> n >> m) {
    int ans = 0;
    for (int i = 0; i != n; ++i)
      for (int j = 0; j != m; ++j) {
        cin >> mine[i][j];
        mark[i][j] = false;
      }
    for (int i = 0; i != n; ++i)
      for (int j = 0; j != m; ++j) {
        if (mark[i][j] || mine[i][j] == '*') continue;
        mark[i][j] = true;
        DFS(i, j);
        ans++;
      }
    cout << ans << endl;
  }

  return 0;
}
