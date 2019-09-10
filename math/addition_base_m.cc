/*
 * @Description: (a+b)_(m)
 * @Author: Chiale
 * @Date: 2019-09-05 13:33:21
 * @LastEditTime: 2019-09-05 13:48:56
 */

#include <iostream>
#include <vector>
using namespace std;

int main(int argc, const char* argv[]) {
  int a, b, m;
  __int128_t c;
  vector<int> cv;
  while (cin >> m >> a >> b) {
    cv.clear();
    c = a + b;
    // 这里需要至少执行一次，想想 0 的情况
    do {
      cv.push_back(c % m);
      c /= m;
    } while (c);
    for (auto i = cv.rbegin(); i != cv.rend(); i++) {
      cout << *i;
    }
    cout << endl;
  }
  return 0;
}
