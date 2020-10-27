#include <iostream>
#include <map>

using namespace std;

int main() {
    int n, m;
    int x;
    while (cin >> n >> m) {
        map<int, bool> record;
        for (int i = 0; i != n; ++i) {
            cin >> x;
            record[x] = true;
        }
        for (int i = 500000; i != -500000; --i) {  //输出前m个数
            if (record[i] == true) {  //若该数字在输入中出现
                cout << i;            //输出该数字
                m--;
                if (m != 0)
                    cout << " ";
                else {
                    cout << endl;
                    break;
                }
            }
        }
    }
    return 0;
}