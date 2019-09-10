/*
 * @Description: pta 1010
 * @Author: Chiale
 * @Date: 2019-09-09 21:19:36
 * @LastEditTime: 2019-09-10 09:03:22
 */
#include <cmath>
#include <iostream>

using namespace std;

long long to_num(const string &b, long long radix) {
  long long res = 0;
  auto lenb = b.size() - 1;
  for (int i = 0; i < b.size(); i++) {
    if (isdigit(b[i])) {
      res += (b[i] - '0') * pow(radix, lenb--);
    } else {
      res += (b[i] - 'a' + 10) * pow(radix, lenb--);
    }

    if (res < 0)
      return -1;
  }
  return res;
}
bool check_radix(long deci, string s, int radix) {
  int value;
  for (auto i = s.rbegin(); i != s.rend(); ++i) {
    if (isdigit(*i))
      value = *i - '0';
    else
      value = *i - 'a' + 10;
    if (value >= radix)
      return false;
    if (value != deci % radix)
      return false;
    deci /= radix;
  }
  if (deci)
    return false;
  return true;
}

int main(int argc, const char *argv[]) {
  string a, b;
  int tag, radix;
  char *tmp;
  while (cin >> a >> b >> tag >> radix) {
    if (tag == 2) {
      swap(a, b);
    }
    auto na = to_num(a, radix);
    auto nb = atoi(b.c_str());
    if (na == 0 && nb == 0) {
      cout << 1 << endl;
      break;
    }
    int i;
    for (i = 2; i != 37; ++i) {
      if (check_radix(na, b, i)) {
        cout << i << endl;
        break;
      }
    }
    if (i == 37)
      cout << "Impossible" << endl;
  }
  return 0;
}
