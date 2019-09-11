/*
 * @Description: leetcode 436
 * @Author: Chiale
 * @Date: 2019-09-11 12:39:01
 * @LastEditTime: 2019-09-11 13:05:12
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
    for (int i = 0; i != n; ++i) {
      maps[buf[i].begin] = i;
    }
    bool first = true;
    for (auto i : buf) {
      if (first)
        first = false;
      else
        cout << " ";
      auto j = maps.lower_bound(i.end);
      if (j == maps.end()) {
        cout << -1 << endl;
      } else {
        cout << j->second << endl;
      }
    }
    cout << endl;
  }
}
