/*
 * @Description: leetcode 84
 * @Author: Chiale
 * @Date: 2019-09-10 14:10:41
 * @LastEditTime: 2019-09-10 14:16:50
 */

#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
  int tmp;
  int n;
  while (cin >> n) {
    vector<int> buf;
    for (int i = 0; i != n; ++i) {
      cin >> tmp;
      buf.push_back(tmp);
    }
    int ans = 0;
    // increase
    stack<int> monoStack;

    // consider the last
    buf.push_back(0);
    // 2
    // 1
    // 1 5
    // 1 5 6
    // 1 2
    // 1 2 3
    // 实际上找到了 nextDecrease
    for (int i = 0; i != buf.size(); ++i) {
      // 这里等号没有关系
      while (!monoStack.empty() && buf[monoStack.top()] > buf[i]) {
        int j = monoStack.top();
        int h = buf[j];
        monoStack.pop();
        int w;
        if (monoStack.empty()) {
          // every one is larger than it
          w = i;
        } else {
          // i and monoStack.top are both impossible
          // so +1 -2 = -1
          w = i - monoStack.top() - 1;
        }
        ans = max(ans, h * w);
      }
      monoStack.push(i);
    }
    cout << ans << endl;
  }
}
