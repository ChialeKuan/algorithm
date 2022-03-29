/*
 * @Description: assign cookies
 * @Author: Chiale
 * @Date: 2020-10-27 13:33:24
 * @LastEditTime: 2022-03-29 10:46:41
 */

#include <iostream>
#include <vector>

using namespace std;

int findContentChildren(vector<int>& g, vector<int>& s) {
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    int i = 0, j = 0;
    int res = 0;
    while (i < g.size() && j < s.size()) {
        if (g[i] <= s[j]) {
            res++;
            i++;
            j++;
        } else {
            j++;
        }
    }
    return res;
}

int main(int argc, const char* argv[]) {
    int n;
    vector<int> children;
    vector<int> cookies;
    while (cin >> n) {
        children.clear();
        cookies.clear();
        children.reserve(n);
        for (auto i = 0; i != n; ++i) {
            int size;
            cin >> size;
            children.push_back(size);
        }
        cin >> n;
        cookies.reserve(n);
        for (auto i = 0; i != n; ++i) {
            int size;
            cin >> size;
            cookies.push_back(size);
        }
        cout << findContentChildren(children, cookies) << endl;
    }
}