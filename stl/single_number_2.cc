/*
 * @Description: 2 single numbers, leetcode 260
 * @Author: Chiale
 * @Date: 2019-09-09 20:34:20
 * @LastEditTime: 2019-09-09 20:49:18
 */

#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

int main(int argc, const char *argv[]) {
  int n;
  vector<int> buf;
  int a, b;
  while (cin >> n) {
    buf.push_back(n);
  }
  int diff = accumulate(buf.begin(), buf.end(), 0, bit_xor<int>());
  // get last set bit;
  // 00111000
  // 11001000
  diff &= -diff;
  for (auto i : buf) {
    if (i & diff) {
      a ^= i;
    } else {
      b ^= i;
    }
  }
  if (a > b)
    swap(a, b);
  cout << a << " " << b << endl;
  return 0;
}