/*
 * @Description: leetcode 216 回溯法
 * @Author: Chiale
 * @Date: 2019-09-13 13:41:14
 * @LastEditTime: 2019-09-13 13:57:55
 */

#include <iostream>
#include <vector>

using namespace std;

vector<int> cur;
vector<vector<int>> ans;

void combinationSum(int k, int n, int begin) {
  if (k == 0 && n == 0) {
    ans.push_back(cur);
    return;
  }
  if (n < 0)
    return;
  for (int i = begin; i < 10; ++i) {
    cur.push_back(i);
    combinationSum(k - 1, n - i, i + 1);
    cur.push_back(i);
  }
}

void printAns() {
  if (ans.empty()) {
    cout << "NULL" << endl;
  }
  for (auto i : ans) {
    bool start = true;
    for (auto j : i) {
      if (start) {
        start = false;
        cout << "[";
      } else {
        cout << " ";
      }
      cout << j;
    }
    cout << "]" << endl;
  }
}

int main() {
  int k, n;
  while (cin >> k >> n) {
    // k numbers to get n, and n will display for only once;
    ans.clear();
    cur.clear();
    combinationSum(k, n, 1);
    printAns();
  }
}
