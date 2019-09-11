#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int tmp;
  vector<int> buf;
  while (cin >> tmp)
    buf.push_back(tmp);

  while (next_permutation(buf.begin(), buf.end())) {
    for (auto i : buf) {
      cout << i << " ";
    }
    cout << endl;
  }
}
