#include <iostream>
#define MAX 20
#define TOTAL 100
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
      dp[i] = INT32_MAX;
    }
    dp[0] = 0;
    for (int i = 1; i != n + 1; ++i) {
      for (int j = weight[i]; j <= total; ++j) {
        if (dp[j - weight[i]] != INT32_MAX &&
            dp[j - weight[i]] + value[i] < dp[j]) {
          dp[j] = dp[j - weight[i]] + value[i];
        }
      }
    }
    if (dp[total] == INT32_MAX) {
      cout << "impossible" << endl;
    } else {
      cout << dp[total] << endl;
    }
  }
  return 0;
}