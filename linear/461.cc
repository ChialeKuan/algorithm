/*
 * @Description: Hamming Distance
 * @Author: Chiale
 * @Date: 2022-03-28 20:43:21
 * @LastEditTime: 2022-03-28 21:32:17
 */

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;

int hammingDistance(int x, int y) {
    int res = 0;
    while (x || y) {
        res += (x & 1) ^ (y & 1);
        x >>= 1;
        y >>= 1;
    }
    return res;
}

int main(int argc, const char *argv[]) {
    int x, y;
    while (cin >> x >> y) {
        cout << hammingDistance(x, y) << endl;
    }
    return 0;
}