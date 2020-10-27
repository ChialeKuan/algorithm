/*
 * @Description: leetcode 455
 * @Author: Chiale
 * @Date: 2020-10-27 13:33:24
 * @LastEditTime: 2020-10-27 13:43:40
 */

#include <iostream>
#include <vector>

using namespace std;

int findContentChildren(vector<int> &children, vector<int> &cookies) {
    sort(children.begin(), children.end());
    sort(cookies.begin(), cookies.end());
    int res = 0;
    int j = 0;
    for (int i : children) {
        while (j != cookies.size() && cookies[j] < i) {
            ++j;
        }
        if (j < cookies.size()) {
            ++res;
            ++j;
        }
    }
    return res;
}

int main() {
    int n;
    vector<int> children;
    vector<int> cookies;
    while (cin >> n) {
        children.clear();
        cookies.clear();
        for (int i = 0; i != n; ++i) {
            int size;
            cin >> size;
            children.push_back(size);
        }
        cin >> n;
        for (int i = 0; i != n; ++i) {
            int size;
            cin >> size;
            cookies.push_back(size);
        }
        cout << findContentChildren(children, cookies) << endl;
    }
}