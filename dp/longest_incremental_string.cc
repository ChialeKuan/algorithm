/*
 * @Description: longest incremental string
 * @Author: Chiale
 * @Date: 2019-09-07 19:58:20
 * @LastEditTime: 2019-09-15 14:40:34
 */

#include <iostream>
#include <vector>


using namespace std;

int main(int argc, const char* argv[]) {
  int num;
  int n;
  int ans;
  while (cin >> n) {
    
    vector<int> nums;
    nums.reserve(n);
    // minimum is 1
    vector<int> len(n, 1);
    for (int i = 0; i != n; ++i) {
      cin >> num;
      nums.push_back(num);
    }

    // solution 1
    for (int i = 0; i != n; ++i) {
      for (int j = 0; j != i; ++j) {
        if (nums[j] < nums[i])
          if (len[j] + 1 > len[i]) len[i] = len[j] + 1;
      }
    }
    ans = *max_element(len.begin(),len.end());
    cout << ans << endl;
  }
  return 0;
}