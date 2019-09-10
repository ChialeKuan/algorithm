/*
 * @Description:pta 1005
 * @Author: Chiale
 * @Date: 2019-09-09 12:33:55
 * @LastEditTime: 2019-09-09 12:34:00
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  string n;
  while (cin >> n) {
    int sum = 0;
    vector<int> digits;
    for (auto i : n) {
      sum += i - '0';
    }
    do {
      digits.push_back(sum % 10);
      sum /= 10;
    } while (sum);
    bool first = true;
    for (auto i = digits.rbegin(); i != digits.rend(); ++i) {
      if (first)
        first = false;
      else
        cout << " ";
      switch (*i) {
        case 0:
          cout << "zero";
          break;
        case 1:
          cout << "one";
          break;
        case 2:
          cout << "two";
          break;
        case 3:
          cout << "three";
          break;
        case 4:
          cout << "four";
          break;
        case 5:
          cout << "five";
          break;
        case 6:
          cout << "six";
          break;
        case 7:
          cout << "seven";
          break;
        case 8:
          cout << "eight";
          break;
        case 9:
          cout << "nine";
          break;
      }
    }
    cout << endl;
  }
}
