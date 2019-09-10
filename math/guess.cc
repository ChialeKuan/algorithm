/*
 * @Description: odd 3n+1 even n/2
 * @Author: Chiale
 * @Date: 2019-08-01 13:55:15
 * @LastEditors: Chiale
 * @LastEditTime: 2019-08-01 14:55:50
 */

#include <iostream>
using namespace std;

int main(int argc, const char* argv[]) {
  long long num;
  int count = 0;
  if (argc >= 2) {
    num = atoi(argv[1]);
  }
  while (num > 1) {
    cout << count++ << " " << num << endl;
    if (num % 2) {
      num = 3 * num + 1;
    } else {
      num = num / 2;
    }
  }
  return 0;
}