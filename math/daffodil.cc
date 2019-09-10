/*
 * @Description: 水仙花数
 * @Author: Chiale
 * @Date: 2019-08-01 23:50:19
 * @LastEditTime: 2019-08-01 23:59:17
 */

#include <iostream>
using namespace std;

int main(int argc, const char* argv[]) {
  for (int i = 1; i != 10; ++i)
    for (int j = 0; j != 10; ++j)
      for (int k = 0; k != 10; ++k) {
        if (i * 100 + j * 10 + k == i * i * i + j * j * j + k * k * k)
          cout << i << j << k << endl;
      }
  return 0;
}
