/*
 * @Description: single number, leetcode 136
 * @Author: Chiale
 * @Date: 2019-09-09 20:34:20
 * @LastEditTime: 2019-09-09 20:42:48
 */

#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

int main(int argc, const char *argv[]) {
  int n;
  vector<int> buf;
  while (cin >> n) {
    buf.push_back(n);
  }
  cout << accumulate(buf.begin(), buf.end(), 0, bit_xor<int>()) << endl;
  return 0;
}