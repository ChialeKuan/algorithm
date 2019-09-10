/*
 * @Description: pta 1008
 * @Author: Chiale
 * @Date: 2019-09-09 18:58:52
 * @LastEditTime: 2019-09-09 19:19:14
 */

#include <iomanip>
#include <iostream>
#include <map>

using namespace std;

int main() {
  int m, n;
  int exp;
  double coe;
  while (cin >> m) {
    map<int, double> num1, num2, ans;
    for (int i = 0; i != m; ++i) {
      cin >> exp >> coe;
      num1[exp] = coe;
    }
    cin >> n;
    for (int i = 0; i != n; ++i) {
      cin >> exp >> coe;
      num2[exp] = coe;
    }

    for (auto i : num1) {
      for (auto j : num2) {
        ans[i.first + j.first] += i.second * j.second;
      }
    }
    for (auto i = ans.begin(); i != ans.end();) {
      if (i->second < 0.01 && i->second > -0.01)
        ans.erase(i++);
      else
        ++i;
    }
    cout << ans.size();
    for (auto i = ans.rbegin(); i != ans.rend(); ++i) {
      cout << " " << i->first << " " << fixed << setprecision(1) << i->second;
    }
    cout << endl;
  }
}
