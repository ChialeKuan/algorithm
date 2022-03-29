/*
 * @Description: Total Hamming Distance
 * @Author: Chiale
 * @Date: 2022-03-28 21:37:51
 * @LastEditTime: 2022-03-29 07:27:29
 */

#include <iostream>
#include <vector>

using namespace std;

int totalHammingDistance(vector<int> &nums) {
    int res = 0;
    int n = nums.size();
    // byte by byte
    for (int i = 0; i < 32; ++i) {
        int cnt = 0;
        for(auto num : nums) {
            cnt += (num >> i) & 1;
        }
        res += cnt * (n - cnt);
    }
    return res;
}

int main(int argc, const char *argv[]) {
    int n;
    while (cin >> n) {
        vector<int> nums(n);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }
        cout << totalHammingDistance(nums) << endl;
    }
    return 0;
}