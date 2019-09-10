#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

struct Goods {
  double j;  // value
  double f;  // cost
  double s;  // v
  bool operator<(const Goods& A) const { return s > A.s; }
};

int main(int argc, const char* argv[]) {
  double m;
  int n;
  Goods item;
  vector<Goods> record;
  while (cin >> m >> n) {
    if (m == -1 && n == -1) break;
    record.clear();
    for (int i = 0; i != n; ++i) {
      cin >> item.j >> item.f;
      item.s = item.j / item.f;
      record.push_back(item);
    }
    sort(record.begin(), record.end());
    int idx = 0;
    double ans = 0;
    while (m > 0 && idx != n) {
      if (m > record[idx].f) {
        ans += record[idx].j;
        m -= record[idx].f;
      } else {
        ans += record[idx].s * m;
        m = 0;
        break;
      }
      idx++;
    }
    cout << fixed << setprecision(3) << ans << endl;
  }
  return 0;
}