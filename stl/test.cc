#include <iostream>
#include <map>
#include <vector>
using namespace std;
int main() {
  map<int, int> maps;
  for (int i = 0; i != 10; ++i)
    cout << maps[i] << endl;
}
