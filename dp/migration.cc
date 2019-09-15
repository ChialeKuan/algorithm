/*
 * @Description: every time two things
 * tiredness = (a-b)^2
 * try to print the minimum of 2k things;
 * @Author: Chiale
 * @Date: 2019-09-08 08:52:43
 * @LastEditTime: 2019-09-15 14:51:41
 */

#include <iostream>
#include <vector>
#define MAX 1000
#define INF 0x7fffffff

using namespace std;

// choose i items from the first j items
// k, n
int dp[MAX][2 * MAX];

int main(int argc, const char *argv[]) {
  int item;
  int n, k;
  int choose;

  while (cin >> n >> k) {
    vector<int> buf;
    // 注意这里寻址从 0 到 n 结束
    buf.reserve(n + 1);
    buf.push_back(0);
    for (int i = 0; i != n; ++i) {
      cin >> item;
      buf.push_back(item);
    }
    for (int j = 0; j != n; ++j) {
      dp[0][j] = 0;
    }
    for (int i = 1; i != k + 1; ++i) {
      for (int j = 2 * i; j != n + 1; ++j) {
        // 注意不能直接转移,j 要从 2i 开始，从 1 开始就相当于可以不装了
        if (j != 2 * i) {
          // 可以从前面的结果递归
          dp[i][j] = dp[i][j - 1];
        } else {
          // 一定要选
          dp[i][j] = INF;
        }
        choose = dp[i - 1][j - 2];
        choose += (buf[j] - buf[j - 1]) * (buf[j] - buf[j - 1]);
        if (choose < dp[i][j]) {
          dp[i][j] = choose;
        }
      }
    }
    cout << dp[k][n] << endl;
  }
  return 0;
}
