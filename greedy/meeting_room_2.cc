/*
 * @Description: leetcode 253
 * @Author: Chiale
 * @Date: 2019-09-11 13:05:25
 * @LastEditTime: 2019-09-11 13:05:35
 */

#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

struct Interval {
  int begin, end;
};

int main() {
  ios::sync_with_stdio(false);
  int n;
  while (cin >> n) {
    vector<Interval> buf;
    buf.reserve(n);
    Interval interval;
    for (int i = 0; i != n; ++i) {
      cin >> interval.begin >> interval.end;
      buf.push_back(interval);
    }

    map<int, int> maps;
    for (auto i : buf) {
      maps[i.begin]++;
      maps[i.end]--;
    }
    int ans, current;
    ans = current = 0;
    for (auto i : maps) {
      current += i.second;
      ans = max(ans, current);
    }
    cout << ans << endl;
  }
}
