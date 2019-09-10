#include <iostream>
#include <string>
using namespace std;

int main() {
  int h;
  while (cin >> h) {
    for (int i = 0; i != h; ++i) {  //依次输出每行信息
      cout << string(2 * h - i * 2 - 1, ' ');
      cout << string(h + 2 * i, '*');
      cout << endl;
    }
  }
  return 0;
}