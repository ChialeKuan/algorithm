/*
 * @Description: from a set of winner string
 * deduce who could be the final winner
 * @Author: Chiale
 * @Date: 2019-09-08 19:01:26
 * @LastEditTime: 2019-09-08 19:15:36
 */

// 实际上就是一个拓扑排序的问题

#include <iostream>
#include <map>
#include <string>

#define MAX 100

using namespace std;

int in[MAX];

int main(int argc, const char* argv[]) {
  int n;
  while (cin >> n) {
    for (int i = 0; i != 2 * n; ++i) {
      in[i] = 0;
    }
    map<string, int> maps;
    int id = 0;
    string name1;
    string name2;
    for (int i = 0; i != n; ++i) {
      cin >> name1 >> name2;
      if (maps.find(name1) == maps.end()) {
        maps[name1] = id++;
      }
      if (maps.find(name2) == maps.end()) {
        maps[name2] = id++;
      }
      in[maps[name2]]++;
    }
    int cnt = 0;
    for (int i = 0; i != id; ++i) {
      if (in[i] == 0) ++cnt;
    }
    if (cnt == 1)
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }
  return 0;
}