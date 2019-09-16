/*
 * @Description: leetcode 37 加法，可以重复用
 * @Author: Chiale
 * @Date: 2019-09-11 13:30:33
 * @LastEditTime: 2019-09-16 08:58:02
 */

#include <iostream>
#include <vector>

using namespace std;

vector<int> cur;
vector<vector<int>> ans;

void combinationSum(vector<int> &buf, int m, int begin) {
  if (m == 0) {
    ans.push_back(cur);
    return;
  }
  for (int i = begin; i < buf.size(); ++i) {
    for (int j = 1; j * buf[i] <= m; ++j) {
      // push k times
      for (int k = 1; k <= j; ++k) {
        cur.push_back(buf[i]);
      }
      combinationSum(buf, m - buf[i] * j, i + 1);
      // pop k times accordingly
      for (int k = 1; k <= j; ++k) {
        cur.pop_back();
      }
    }
  }
}

void printSum() {
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
  int m, n;
  while (cin >> m >> n) {
    int tmp;
    vector<int> buf;
    ans.clear();

    for (int i = 0; i != n; ++i) {
      cin >> tmp;
      buf.push_back(tmp);
    }
    combinationSum(buf, m, 0);
    printSum();
  }
}
