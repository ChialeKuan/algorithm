#include <bitset>
#include <iostream>
#include <vector>
#define MAX 100
using namespace std;

struct Item {
    int w;
    int v;
    int c;  // copies
};

int dp[MAX];

int main(int argc, const char* argv[]) {
    int w, v, c;
    int volume, n;
    int base;
    while (cin >> volume >> n) {
        Item item;
        vector<Item> items;
        // 第 0 项先装进去
        // items.push_back(item);
        // 分拆
        for (int i = 0; i != n; ++i) {
            cin >> w >> v >> c;
            base = 1;
            bitset<32> c_bit(c);
            for (auto i = 0; i != c_bit.size(); ++i) {
                if (c_bit[i]) {
                    item.w = w * base;
                    item.v = v * base;
                    item.c = base;
                    items.push_back(item);
                }
                base *= 2;
            }
        }
        for (int i = 0; i != n; ++i) {
            dp[i] = 0;
        }
        for (int i = 0; i != items.size(); ++i) {
            for (int j = volume; j >= items[i].w; --j) {
                if (dp[j] < dp[j - items[i].w] + items[i].v) {
                    dp[j] = dp[j - items[i].w] + items[i].v;
                }
            }
        }
        cout << dp[volume] << endl;
    }
    return 0;
}