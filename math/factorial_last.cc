/*
 * @Description: 1!+2!+3!+...+n!(mod N)
 * @Author: Chiale
 * @Date: 2019-08-01 14:18:49
 * @LastEditTime: 2019-09-05 13:08:01
 */

#include <ctime>
#include <iostream>

using namespace std;

int main(int argc, const char* argv[]) {
  int n;
  int N;
  long item = 1;
  long long sum = 0;
  if (argc != 3)
    return 1;
  else {
    n = atoi(argv[1]);
    N = atoi(argv[2]);
  }
  auto start = clock();
  for (int i = 1; i != n + 1; ++i) {
    item *= i;
    item %= N;
    sum += item;
    sum %= N;
  }
  cout << sum << endl;
  cout << (clock() - start) / 1000.0 << " ms" << endl;
  return 0;
}