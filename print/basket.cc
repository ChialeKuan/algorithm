/*
 * @Description: 输出一个框
 * @Author: Chiale
 * @Date: 2019-09-03 21:30:07
 * @LastEditTime: 2019-09-15 09:07:11
 */

#include <iostream>

using namespace std;

int main() {
  char buf[82][82];  //用于预排版的输出缓存
  char a, b;         //输入的两个字符
  int n;             //叠框大小
  bool first = true;
  char c;
  while (cin >> n >> a >> b) {
    if (first) {
      first = false;
    } else {
      cout << endl;
    }
    for (int loop = 0; loop <= n / 2; ++loop) {
      if (loop % 2) {
        c = a;
      } else {
        c = b;
      }
      for (int i = loop; i != n - loop; ++i) {
        buf[loop][i] = c;
        buf[i][loop] = c;
        buf[n - loop - 1][i] = c;
        buf[i][n - loop - 1] = c;
      }
    }
    // 角落的空格
    if (n > 1) {
      buf[0][0] = buf[0][n - 1] = buf[n - 1][0] = buf[n - 1][n - 1] = ' ';
    }
    for (int i = 0; i != n; ++i) {
      for (int j = 0; j != n; ++j) {
        cout << buf[i][j];
      }
      cout << endl;
    }
  }
  return 0;
}
