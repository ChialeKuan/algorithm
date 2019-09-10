/*
 * @Description: n! (n<1000)
 * @Author: Chiale
 * @Date: 2019-09-05 19:32:15
 * @LastEditTime: 2019-09-05 20:06:05
 */

#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

vector<int> multiply(const vector<int> &x, const int &y) {
  vector<int> z;
  int temp, carry = 0;
  for (int i = 0; i != x.size(); ++i) {
    temp = x[i] * y + carry;
    z.push_back(temp % 10000);
    carry = temp / 10000;
  }
  if (carry) z.push_back(carry);
  return z;
}
int main(int argc, const char *argv[]) {
  int n;
  int temp;
  vector<int> n_v;

  while (cin >> n) {
    n_v.clear();
    temp = n;
    do {
      n_v.push_back(temp % 10000);
      temp /= 10000;
    } while (temp);
    for (int i = n - 1; i; --i) {
      n_v = multiply(n_v, i);
    }
    cout << setw(0) << n_v[n_v.size() - 1];
    cout << setw(4) << setfill('0');
    for (auto i = n_v.rbegin() + 1; i != n_v.rend(); ++i) {
      cout << *i;
    }
    cout << endl;
  }

  return 0;
}