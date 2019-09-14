/*
 * @Description: leetcode 410
 * @Author: Chiale
 * @Date: 2019-09-14 18:50:32
 * @LastEditTime: 2019-09-14 18:50:41
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int k, n;
vector<int> buf;

bool valid(int target) {
    int curr = 0;
    int kk = k;
    for (auto i: buf) {
        if (curr + i <= target) {
            curr += i;
        } else {
            curr = i;
            if (--kk == 0 || curr > target) return false;
        }
    }
    return true;
}

int main() {
    int tmp;

    while (cin >> k >> n) {
        buf.clear();
        buf.reserve(n);
        for (int i = 0; i != n; ++i) {
            cin >> tmp;
            buf.push_back(tmp);
        }
        auto left = 0, right = 0;
        for (auto i:buf) {
            left = max(left, i);
            right += i;
        }
        // [)
        while (right - left > 5) {
            int mid = (left + right) / 2;
            if (valid(mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        while (!valid(left)) ++left;
        cout << left << endl;
    }
}
