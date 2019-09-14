/*
 * @Description: leetcode 325
 * @Author: Chiale
 * @Date: 2019-09-14 18:57:37
 * @LastEditTime: 2019-09-14 18:58:56
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int k, n;
vector<int> buf;

int main() {
    int tmp;

    while (cin >> k >> n) {
        buf.clear();
        buf.reserve(n);
        for (int i = 0; i != n; ++i) {
            cin >> tmp;
            buf.push_back(tmp);
        }
        unordered_map<int, int> hash;
        int ans = 0;
        hash[0] = -1;
        int sum = 0;
        for (int i = 0; i != buf.size(); ++i) {
            sum += buf[i];
            if (!hash.count(sum)) {
                hash[sum] = i;
            }
            if (hash.count(sum - k)) {
                ans = max(ans, i - hash[sum - k]);
            }
        }
        cout << ans << endl;
    }
}
