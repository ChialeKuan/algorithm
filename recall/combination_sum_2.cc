/*
 * @Description: leetcode 40
 * @Author: Chiale
 * @Date: 2019-09-13 13:28:13
 * @LastEditTime: 2019-09-13 13:28:34
 */

#include <iostream>
#include <vector>

using namespace std;

vector<int> cur;
vector<vector<int>> ans;

// 1
// 1 2 2
// 1 2
// 1
//
// 2
// 2 2
// 2
//

void combinationSum(vector<int> &buf, int m, int begin) {
  if (m == 0) {
    ans.push_back(cur);
    return;
  }
  if (m < 0)
    return;
  for (int i = begin; i < buf.size(); ++i) {
    // you can only push the element in unless it is the first element of its
    // kind
    if (i == begin || buf[i] != buf[i - 1]) {
      cur.push_back(buf[i]);
      // cout << "push:\t" << buf[i] << endl;
      combinationSum(buf, m - buf[i], i + 1);
      cur.pop_back();
      // cout << "pop:\t" << buf[i] << endl;
    }
  }
}

void printAns() {
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
    cur.clear();

    for (int i = 0; i != n; ++i) {
      cin >> tmp;
      buf.push_back(tmp);
    }
    sort(buf.begin(), buf.end());
    combinationSum(buf, m, 0);
    printAns();
  }
}
