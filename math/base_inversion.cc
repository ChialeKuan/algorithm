/*
 * @Description:base invert $1 from $0 to $2
 * @Author: Chiale
 * @Date: 2019-09-05 13:51:15
 * @LastEditTime: 2019-09-05 17:14:02
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(int argc, const char* argv[]) {
  vector<int> v;
  int fBase, tBase;
  int value;
  string fString, tString;
  while (cin >> fBase >> fString >> tBase) {
    value = 0;
    v.clear();
    for (auto i = fString.begin(); i != fString.end(); ++i) {
      value *= fBase;
      if (isdigit(*i))
        value += *i - '0';
      else if (islower(*i))
        value += *i - 'a' + 10;
      else if (isupper(*i))
        value += *i - 'A' + 10;
    }
    do {
      v.push_back(value % tBase);
      value /= tBase;
    } while (value);
    for (auto i = v.rbegin(); i != v.rend(); ++i) {
      if (*i < 10)
        cout << *i;
      else {
        cout << char(*i - 10 + 'A');
      }
    }
    cout << endl;
  }
  return 0;
}