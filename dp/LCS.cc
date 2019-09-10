/*
 * @Description: Longest Common String
 * @Author: Chiale
 * @Date: 2019-09-07 20:14:07
 * @LastEditTime: 2019-09-08 09:08:54
 */

#include <iostream>
#include <string>
#define MAX 100

using namespace std;

int dp[MAX + 1][MAX + 1];

int main(int argc, const char* argv[]) {
  string a, b;
  while (cin >> a >> b) {
    if (!a.size() || !b.size()) {
      cout << 0 << endl;
      continue;
    }
    for (int i = 0; i <= a.size(); ++i) dp[i][0] = 0;
    for (int i = 0; i <= b.size(); ++i) dp[0][i] = 0;
    for (int i = 1; i <= a.size(); ++i)
      for (int j = 1; j <= b.size(); ++j)
        if (a[i - 1] == b[j - 1])
          dp[i][j] = dp[i - 1][j - 1] + 1;
        else {
          if (dp[i - 1][j] >= dp[i][j - 1])
            dp[i][j] = dp[i - 1][j];
          else
            dp[i][j] = dp[i][j - 1];
        }
    cout << dp[a.size()][b.size()] << endl;
  }

  return 0;
}