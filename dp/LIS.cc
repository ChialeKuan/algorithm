/*
 * @Description: longest incremental string
 * @Author: Chiale
 * @Date: 2019-09-07 19:58:20
 * @LastEditTime: 2019-09-07 20:13:07
 */

#include <iostream>
#include <vector>
using namespace std;

int main(int argc, const char* argv[]) {
  int num;
  int n;
  int ans;
  while (cin >> n) {
    // ans = 0;
    vector<int> nums;
    vector<int> len;
    for (int i = 0; i != n; ++i) {
      cin >> num;
      nums.push_back(num);
      // minimum is 1
      len.push_back(1);
    }

    for (int i = 0; i != n; ++i) {
      for (int j = 0; j != i; ++j) {
        if (nums[j] < nums[i])
          if (len[j] + 1 > len[i]) len[i] = len[j] + 1;
      }
    }
    // for (auto i : len) {
    //   if (i > ans) ans = i;
    // }
    cout << len[n - 1] << endl;
  }
  return 0;
}