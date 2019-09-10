#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(int argc, const char* argv[]) {
  int carry;
  int temp;
  string m, n;
  vector<int> m_v, n_v, sum_v;

  while (cin >> m >> n) {
    carry = 0;
    m_v.clear();
    n_v.clear();
    sum_v.clear();
    for (auto i = m.rbegin(); i != m.rend(); ++i) {
      m_v.push_back(*i - '0');
    }
    for (auto i = n.rbegin(); i != n.rend(); ++i) {
      n_v.push_back(*i - '0');
    }
    for (int i = 0; i < m_v.size() || i < n_v.size(); ++i) {
      temp = carry;
      if (i < m_v.size()) {
        temp += m_v[i];
      }
      if (i < n_v.size()) {
        temp += n_v[i];
      }
      sum_v.push_back(temp % 10);
      carry = temp / 10;
    }
    if (carry) {
      sum_v.push_back(carry);
    }
    for (auto i = sum_v.rbegin(); i != sum_v.rend(); ++i) cout << *i;
    cout << endl;
  }
  return 0;
}