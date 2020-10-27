/*
 * @Description: town, road, (t1,t2) 连通集数量
 * @Author: Chiale
 * @Date: 2019-09-06 12:50:02
 * @LastEditTime: 2019-09-06 13:10:53
 */

#include <iostream>
#include <typeinfo>
#include <vector>

#define N 1000

using namespace std;

int tree[N];

int findRoot(int x) {
    if (tree[x] == -1) return x;
    int tmp = findRoot(tree[x]);
    tree[x] = tmp;
    return tmp;
}

int main(int argc, const char* argv[]) {
    int ans;
    int n, m;
    int a, b;
    while (cin >> n >> m) {
        ans = 0;
        for (int i = 1; i != n + 1; ++i) tree[i] = -1;
        for (int i = 0; i != m; ++i) {
            cin >> a >> b;
            a = findRoot(a);
            b = findRoot(b);
            if (a != b) tree[a] = b;
        }
        for (int i = 1; i != n + 1; ++i) {
            if (tree[i] == -1) ++ans;
        }
        cout << ans - 1 << endl;
    }

    return 0;
}