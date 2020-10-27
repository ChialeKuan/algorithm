#include <iostream>
#define N 100
#define M 1000

using namespace std;

// index  <= N + 1
// volume  <= M + 1

int dp[N + 1][M + 1];
int dp_[M + 1];
int weight[N + 1];
int value[N + 1];

int total_w, total_n;

void dim_2() {
    int tmp;
    for (int i = 0; i != total_w + 1; ++i) {
        dp[0][i] = 0;
    }
    for (int i = 1; i != total_n + 1; ++i) {
        for (int j = 0; j != total_w + 1; ++j) {
            dp[i][j] = dp[i - 1][j];
            if (j >= weight[i]) {
                // 如果可以装下
                // 这里可以看出 dp 实际上可以用一位数组来实现
                dp[i][j] = dp[i - 1][j];
                // 注意这里是 i - 1， 不是 i
                tmp = dp[i - 1][j - weight[i]] + value[i];
                if (tmp > dp[i][j]) {
                    dp[i][j] = tmp;
                    // cout << tmp << "!" << endl;
                }
            }
        }
    }
    cout << dp[total_n][total_w] << endl;
}

void dim_1() {
    for (int i = 0; i != total_w + 1; ++i) {
        dp_[i] = 0;
    }
    for (int i = 1; i != total_n + 1; ++i) {
        for (int j = total_w; j >= weight[i]; --j) {
            // 反向更新，事实上只能从上一级里面多取一个
            if (dp_[j - weight[i]] + value[i] > dp_[j])
                dp_[j] = dp_[j - weight[i]] + value[i];
        }
    }
    cout << dp_[total_w] << endl;
}

void dim_1_not_bool() {
    for (int i = 0; i != total_w + 1; ++i) {
        dp_[i] = 0;
    }
    for (int i = 1; i != total_n + 1; ++i) {
        for (int j = weight[i]; j <= total_w + 1; ++j) {
            //  正向更新，可以取很多歌
            if (dp_[j - weight[i]] + value[i] > dp_[j])
                dp_[j] = dp_[j - weight[i]] + value[i];
        }
    }
    cout << dp_[total_w] << endl;
}

int main(int argc, const char* argv[]) {
    while (cin >> total_w >> total_n) {
        for (int i = 1; i != total_n + 1; ++i) {
            cin >> weight[i] >> value[i];
        }
        cout << "1D:\t";
        dim_1();
        cout << "2D:\t";
        dim_2();
        cout << "MANY:\t";
        dim_1_not_bool();
    }
    return 0;
}