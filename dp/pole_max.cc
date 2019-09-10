/*
 * @Description: maximum number for two piles with the same weight
 * @Author: Chiale
 * @Date: 2019-09-08 10:09:58
 * @LastEditTime: 2019-09-08 13:59:43
 */

#include <algorithm>
#include <iostream>

// 重量从-2000到2000
#define MAX_N 10
#define MAX_W 20
using namespace std;

int dp[MAX_N + 1][2 * MAX_W + 1];
int buf[MAX_N + 1];

int main(int argc, const char* argv[]) {
  int item;
  int n;
  int tmp1, tmp2, tmp3;

  while (cin >> n) {
    bool haveZero = false;
    int cnt = 0;
    for (int i = 0; i != n; ++i) {
      cin >> item;
      if (item) {
        buf[++cnt] = item;
      } else {
        haveZero = true;
      }
    }
    n = cnt;
    for (int i = -MAX_W; i != MAX_W + 1; ++i) {
      dp[0][i + MAX_W] = INT32_MIN;
    }
    dp[0][0 + MAX_W] = 0;
    for (int i = 1; i != n + 1; ++i) {
      for (int j = -MAX_W; j != MAX_W + 1; ++j) {
        tmp1 = INT32_MIN;
        tmp2 = INT32_MIN;
        tmp3 = dp[i - 1][j + MAX_W];
        if (j + buf[i] <= MAX_W && dp[i - 1][j + buf[i] + MAX_W] != INT32_MIN) {
          // 不超界，前面不会不可取
          tmp1 = dp[i - 1][j + buf[i] + MAX_W] + buf[i];
        }
        if (j - buf[i] >= -MAX_W &&
            dp[i - 1][j - buf[i] + MAX_W] != INT32_MIN) {
          tmp2 = dp[i - 1][j - buf[i] + MAX_W] + buf[i];
        }
        if (tmp1 < tmp2) tmp1 = tmp2;
        if (tmp1 < tmp3) tmp1 = tmp3;
        dp[i][j + MAX_W] = tmp1;
      }
    }
    if (dp[n][MAX_W] == 0) {
      if (haveZero) {
        cout << 0 << endl;
      } else {
        cout << -1 << endl;
      }
    } else {
      cout << dp[n][MAX_W] / 2 << endl;
    }
  }
  return 0;
}
