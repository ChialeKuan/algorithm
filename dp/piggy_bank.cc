/*
 * @Description: 最少可能装多少钱
 * @Author: Chiale
 * @Date: 2019-09-08 15:15:38
 * @LastEditTime: 2019-09-15 14:55:49
 */

#include <iostream>
#define MAX 20
#define TOTAL 100
#define INF 0x7fffffff

using namespace std;

int total;
int n;
int value[MAX + 1];
int weight[MAX + 1];
int dp[TOTAL + 1];

int main(int argc, const char* argv[]) {
  while (cin >> total >> n) {
    for (int i = 1; i != n + 1; ++i) {
      cin >> value[i] >> weight[i];
    }

    for (int i = 0; i != total + 1; ++i) {
      // not transferrable
      dp[i] = INF;
    }
    dp[0] = 0;
    for (int i = 1; i != n + 1; ++i) {
      for (int j = weight[i]; j <= total; ++j) {
        if (dp[j - weight[i]] != INF &&
            dp[j - weight[i]] + value[i] < dp[j]) {
          dp[j] = dp[j - weight[i]] + value[i];
        }
      }
    }
    if (dp[total] == INF) {
      cout << "impossible" << endl;
    } else {
      cout << dp[total] << endl;
    }
  }
  return 0;
}