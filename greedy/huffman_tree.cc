#include <iostream>
#include <queue>

using namespace std;

// 最小堆
priority_queue<int, vector<int>, greater<int>> q;

int main(int argc, const char* argv[]) {
  int n;
  while (cin >> n) {
    while (!q.empty()) {
      q.pop();
    }
    int node;
    for (int i = 0; i != n; ++i) {
      cin >> node;
      q.push(node);
    }
    int ans = 0;
    int a, b;
    while (q.size() > 1) {
      a = q.top();
      q.pop();
      b = q.top();
      q.pop();
      // 每一层加一次
      ans += a + b;
      q.push(a + b);
    }
    cout << ans << endl;
  }
  return 0;
}
