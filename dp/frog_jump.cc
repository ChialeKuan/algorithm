/*
 * @Description: leetcode 403
 * @Author: Chiale
 * @Date: 2019-09-09 20:54:37
 * @LastEditTime: 2019-09-10 10:03:26
 */
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;
unordered_map<uint64_t, bool> dp;

bool canCross(vector<int> &stones, int pos = 0, int k = 0) {
  auto key = k | static_cast<uint64_t>(pos) << 32;
  if (dp.count(key))
    return dp[key];
  for (int i = pos + 1; i < stones.size(); ++i) {
    int gap = stones[i] - stones[pos];
    if (gap < k - 1)
      continue;
    if (gap > k + 1) {
      dp[key] = false;
      return false;
    }
    if (canCross(stones, i, gap)) {
      dp[key] = true;
      return true;
    }
  }
  if (pos == stones.size() - 1) {
    dp[key] = true;
    return true;
  } else {
    dp[key] = false;
    return false;
  }
}

int main(int argc, const char *argv[]) {
  int n;
  int tmp;
  vector<int> stones;
  while (cin >> n) {
    stones.clear();
    dp.clear();
    for (int i = 0; i != n; ++i) {
      cin >> tmp;
      stones.push_back(tmp);
    }

    if (canCross(stones))
      cout << "true" << endl;
    else
      cout << "false" << endl;
  }
  return 0;
}
