/*
 * @Description: 12*45=1*4+1*5+2*4+2*5
 * @Author: Chiale
 * @Date: 2019-09-05 13:15:15
 * @LastEditTime: 2019-09-05 13:28:38
 */

#include <iostream>
#include <vector>
#define DEBUG
using namespace std;

int main(int argc, const char* argv[]) {
  long long m;
  long long n;
  int ms;
  int ns;
  vector<int> mv;
  vector<int> nv;
  while (cin >> m >> n) {
    mv.clear();
    nv.clear();
    while (m) {
      mv.push_back(m % 10);
      m /= 10;
    }
    while (n) {
      nv.push_back(n % 10);
      n /= 10;
    }
    ms = 0;
    ns = 0;
    for (auto i : mv) {
      ms += i;
    }
    for (auto i : nv) {
      ns += i;
    }
#ifdef DEBUG
    cout << "capacity:\t" << mv.capacity() << nv.capacity() << endl;
#endif
    cout << ms * ns << endl;
  }
  return 0;
}