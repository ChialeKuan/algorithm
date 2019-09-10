#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Program {
  int begin;
  int end;
  bool operator<(const Program& A) const { return end < A.end; }
};

int main(int argc, const char* argv[]) {
  int n;
  while (cin >> n) {
    if (n == 0) break;
    int now = 0;
    int ans = 0;
    Program p;
    vector<Program> buf;
    for (int i = 0; i != n; ++i) {
      cin >> p.begin >> p.end;
      buf.push_back(p);
    }
    sort(buf.begin(), buf.end());
    for (int i = 0; i != n; ++i) {
      if (now <= buf[i].begin) {
        now = buf[i].end;
        ++ans;
      }
    }
    cout << ans << endl;
  }
  return 0;
}