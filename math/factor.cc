/*
 * @Description: a^b last three digits
 * @Author: Chiale
 * @Date: 2019-09-05 16:48:35
 * @LastEditTime: 2019-09-05 18:47:56
 */

#include <bitset>
#include <iostream>
#include <vector>

#define MAX 128

using namespace std;

int main(int argc, const char* argv[]) {
  int a, b;
  __uint64_t t;
  int ans;

  while (cin >> a >> b) {
    bitset<MAX> b_bits(b);
    ans = 1;
    t = a;
    for (int i = 0; i != b_bits.size(); ++i) {
      if (b_bits[i]) {
        ans *= t;
        ans %= 1000;
      }
      t *= t;
      t %= 1000;
    }
    cout << ans << endl;
  }
  return 0;
}