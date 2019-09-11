/*
 * @Description: leetcode 435
 * @Author: Chiale
 * @Date: 2019-09-10 15:12:32
 * @LastEditTime: 2019-09-10 15:18:19
 */
#include <iostream>

#include <algorithm>
#include <vector>

using namespace std;

struct Interval {
  int begin, end;
  bool operator<(const Interval &x) const { return begin < x.begin; }
};

int main() {
  int n;
  while (cin >> n) {
    vector<Interval> buf;
    Interval interval;
    for (int i = 0; i != n; ++i) {
      cin >> interval.begin >> interval.end;
      buf.push_back(interval);
    }
    sort(buf.begin(), buf.end());
    int ans = 0;
    auto pre = 0;
    for (int i = 1; i != buf.size(); ++i) {
      if (buf[i].begin < buf[pre].end) {
        // overlap
        ++ans;
        // 删去 end 比较大的那一个
        if (buf[i].end < buf[pre].end) {
          pre = i;
        }
      } else {
        pre = i;
      }
    }
    cout << ans << endl;
  }
}
