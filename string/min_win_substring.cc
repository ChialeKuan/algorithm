/*
 * @Description: leetcode 76
 * @Author: Chiale
 * @Date: 2019-09-09 16:36:16
 * @LastEditTime: 2019-09-09 19:58:07
 */

#include <iostream>
#include <map>
#include <string>
#define MAX 0x7ffffff

using namespace std;

int main() {
  string s, t;
  while (cin >> s >> t) {
    map<char, int> maps;
    for (auto i : t) {
      maps[i]++;
    }
    string::size_type begin = 0, end = 0, head = 0, d = MAX, count = t.size();
    // count: the num not in s
    while (end <= s.size()) {
      // collect all the vacancy
      if (maps[s[end]] > 0)
        --count;
      --maps[s[end]];
      ++end;
      // try to shrink by the front
      while (count == 0) {
        if (d > end - begin) {
          d = end - begin;
          head = begin;
        }
        ++maps[s[begin]];
        if (maps[s[begin]] > 0)
          ++count;
        ++begin;
      }
    }
    if (d == MAX)
      cout << endl;
    else
      cout << s.substr(head, d) << endl;
  }
}
