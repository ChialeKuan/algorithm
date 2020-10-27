/*
 * @Description: n m (a,b,c)
 * @Author: Chiale
 * @Date: 2019-09-06 14:18:25
 * @LastEditTime: 2019-09-15 16:09:34
 */

#include <iostream>
#include <vector>
#define INF 0x7fffffff

using namespace std;

int main(int argc, const char* argv[]) {
    vector<int> vec;
    vector<vector<int>> buf;
    int m, n;
    int a, b, c;
    while (cin >> n >> m) {
        vec.clear();
        buf.clear();
        for (int i = 0; i != n; ++i) vec.push_back(INF);
        for (int i = 0; i != n; ++i) buf.push_back(vec);
        for (int i = 0; i != m; ++i) {
            cin >> a >> b >> c;
            --a;
            --b;
            buf[a][b] = c;
            buf[b][a] = c;
        }
        for (int k = 0; k != n; ++k)
            for (int i = 0; i != n; ++i)
                for (int j = 0; j != n; ++j)
                    if (buf[i][k] + buf[k][j] < buf[i][j]) {
                        buf[i][j] = buf[i][k] + buf[k][j];
                    }
        cout << buf[0][n - 1] << endl;
    }

    return 0;
}