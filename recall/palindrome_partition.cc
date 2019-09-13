/*
 * @Description: leetcode 131
 * @Author: Chiale
 * @Date: 2019-09-13 14:23:47
 * @LastEditTime: 2019-09-13 14:23:57
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> cur;
vector<vector<string>> ans;

bool isPalindrome(const string &str, int begin, int end) {
  while (begin < end)
    if (str[begin++] != str[end--]) {
      return false;
    }
  return true;
}

void partition(string str, int begin) {
  if (begin == str.size()) {
    ans.push_back(cur);
    return;
  }
  for (int i = begin; i < str.size(); ++i) {
    if (isPalindrome(str, begin, i)) {
      cur.push_back(str.substr(begin, i - begin + 1));
      partition(str, i + 1);
      cur.pop_back();
    }
  }
}

void printAns() {
  if (ans.empty()) {
    cout << "NULL" << endl;
    return;
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
  ios::sync_with_stdio(false);
  string str;
  while (cin >> str) {
    cur.clear();
    ans.clear();
    partition(str, 0);
    printAns();
  }
}
