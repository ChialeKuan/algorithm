/*
 * @Description: unordered map
 * @Author: Chiale
 * @Date: 2019-09-03 13:55:08
 * @LastEditTime: 2019-09-15 13:10:28
 */

#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
  int n;
  int x;
  unordered_map<int, int> record;

  while (cin >> n && n != 0) {
    for (int i = 0; i != n; ++i) {
      cin >> x;
      record[x]++;
    }
    cin >> x;
    cout << record[x] << endl;
  }
  return 0;
}