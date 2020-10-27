/*
 * @Description: leetcode 644 len >= k
 * @Author: Chiale
 * @Date: 2019-09-14 13:31:50
 * @LastEditTime: 2020-10-27 14:15:21
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

double findMaxAverage(const vector<int>& buf, int k) {
    auto n = buf.size();
    vector<double> surplus(n + 1, 0);
    double left = *min_element(buf.begin(), buf.end());
    double right = *max_element(buf.begin(), buf.end());
    while (right - left > 1e-5) {
        double checkmark = 0;
        double mid = (left + right) / 2;
        bool check = false;
        for (int i = 1; i != n; ++i) {
            surplus[i] = surplus[i - 1] + buf[i - 1] - mid;
            if (i >= k) {
                // 前面有个冤大头，是个负的
                checkmark = min(checkmark, surplus[i - k]);
            }
            if (i >= k && surplus[i] > checkmark) {
                check = true;
                break;
            }
        }
        if (check) {
            left = mid;
        } else {
            right = mid;
        }
    }
    return left;
}

int main() {
    int n, k;
    while (cin >> n >> k) {
        int temp;
        vector<int> buf;
        for (int i = 0; i != n; ++i) {
            cin >> temp;
            buf.push_back(temp);
        }
        cout << findMaxAverage(buf, k) << endl;
    }
}
