/*
 * @Description: 单调栈
 * @Author: Chiale
 * @Date: 2019-09-10 10:09:56
 * @LastEditTime: 2019-09-10 14:07:06
 */

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
  int tmp;
  int n;
  while (cin >> n) {
    vector<int> buf;
    vector<int> ans(n, -1);
    // decrease
    stack<int> monoStack;

    for (int i = 0; i != n; ++i) {
      cin >> tmp;
      buf.push_back(tmp);
    }
    // 5
    // 5 3
    // 5 3 1
    // 5 3 2
    // 5
    // 5 4
    for (int i = 0; i != buf.size(); ++i) {
      while (!monoStack.empty() && buf[monoStack.top()] < buf[i]) {
        ans[monoStack.top()] = i - monoStack.top();
        monoStack.pop();
      }
      monoStack.push(i);
    }
    bool first = true;
    for (auto i : ans) {
      if (first)
        first = false;
      else
        cout << " ";
      cout << i;
    }
    cout << endl;
  }
}
