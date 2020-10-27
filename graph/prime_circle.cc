/*
 * @Description: prime circle n<17
 * @Author: Chiale
 * @Date: 2019-09-07 14:01:27
 * @LastEditTime: 2019-09-07 15:13:33
 */

#include <iostream>
#include <vector>
#define MAX 20
using namespace std;

int n;
int ans[MAX];
bool mark[MAX];

bool isPrime(int x) {
    for (int i = 2; i * i <= x; ++i) {
        if (x % i == 0) return false;
    }
    return true;
}

void printAns() {
    for (int i = 1; i != n + 1; ++i) {
        cout << ans[i];
        if (i != n) cout << " ";
    }
    cout << endl;
}
void DFS(int num) {
    if (num > 1) {
        if (!isPrime(ans[num - 1] + ans[num])) return;
    }
    if (num == n) {
        if (!isPrime(ans[1] + ans[n])) return;
        printAns();
        return;
    }
    for (int i = 2; i != n + 1; ++i) {
        if (mark[i]) continue;
        mark[i] = true;
        ans[num + 1] = i;
        DFS(num + 1);
        mark[i] = false;
    }
}

int main(int argc, const char *argv[]) {
    int times = 0;
    while (cin >> n) {
        ++times;
        for (int i = 0; i != MAX; ++i) {
            ans[i] = 0;
            mark[i] = false;
        }
        ans[1] = 1;
        mark[1] = true;
        cout << "Case " << times << ":" << endl;
        DFS(1);
    }
    return 0;
}
