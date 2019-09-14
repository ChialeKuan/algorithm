/*
 * @Description: leetcode 209
 * @Author: Chiale
 * @Date: 2019-09-14 18:22:10
 * @LastEditTime: 2019-09-14 18:24:56
 */

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

#define MAX 0x7fffffff

using namespace std;

int main() {
    int k, n;
    int tmp;
    while (cin >> k >> n) {
        vector<int> buf;
        buf.reserve(n);
        for (int i = 0; i != n; ++i) {
            cin >> tmp;
            buf.push_back(tmp);
        }
        vector<int> sums(n + 1);
        for (int i = 0; i != n; ++i) {
            sums[i + 1] = sums[i] + buf[i];
        }
        int ans = MAX;
        int left, right;
        for (left = 0, right = 1; right < n; ++right) {
            while (right != n - 1 && sums[right] - sums[left] < k) ++right;
            while (left < right && sums[right] - sums[left + 1] >= k) ++left;
            if (sums[right] - sums[left] >= k) {
                ans = min(ans, right - left + 1);
            }
        }
        if (ans == MAX) {
            cout << 0 << endl;
        } else {
            cout << ans << endl;
        }
    }
}
