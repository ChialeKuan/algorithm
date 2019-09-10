/*
 * @Description: pta 1007
 * @Author: Chiale
 * @Date: 2019-09-09 15:33:33
 * @LastEditTime: 2019-09-09 15:33:41
 */

#include <iostream>
#include <vector>

#define MIN 0x80000000

using namespace std;

int main() {
  int tmp;
  int n;

  while (cin >> n) {
    vector<int> buf;

    for (int i = 0; i != n; ++i) {
      cin >> tmp;
      buf.push_back(tmp);
    }

    int s = 0;
    int e = 0;
    int max = MIN;
    int max_s = 0;
    int max_e = 0;
    tmp = 0;
    for (int i = 0; i != n; ++i) {
      if (tmp > 0) {
        tmp += buf[i];
        e = i;
      } else {
        tmp = buf[i];
        s = e = i;
      }
      if (tmp > max) {
        max = tmp;
        max_s = s;
        max_e = e;
      }
    }
    if (max < 0) {
      max = 0;
      max_s = 0;
      max_e = n - 1;
    }

    cout << max << " " << buf[max_s] << " " << buf[max_e] << endl;
  }
}
