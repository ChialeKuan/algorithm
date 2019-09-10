#include <iomanip>
#include <iostream>
#include <queue>
#include <string>

using namespace std;

struct big {
 public:
  deque<int> val;
  void clear() { val.clear(); }
  bool empty() {
    for (auto i = val.begin(); i != val.end(); ++i) {
      if (*i) return false;
    }
    return true;
  }
  void set(int x) {
    clear();
    do {
      val.push_back(x % 10000);
      x /= 10000;
    } while (x);
  }
  friend ostream& operator<<(ostream& out, const big& r) {
    bool start = true;
    if (r.val.empty()) {
      out << 0;
      return out;
    }
    for (auto i = r.val.rbegin(); i != r.val.rend(); ++i) {
      if (start) {
        out << setw(0);
        out << *i;
        start = false;
      } else {
        out << setw(4) << setfill('0') << *i;
      }
    }
    return out;
  }

  big operator+(const big& x) const {
    big ret;
    int temp, carry = 0;
    for (int i = 0; i < val.size() || i < x.val.size(); ++i) {
      temp = carry;
      if (i < val.size()) temp += val[i];
      if (i < x.val.size()) temp += x.val[i];
      ret.val.push_back(temp % 10000);
      carry = temp / 10000;
    }
    if (carry) {
      ret.val.push_back(carry);
    }
    return ret;
  }

  big operator*(int x) const {
    big ret;
    int temp, carry = 0;
    for (auto i = val.begin(); i != val.end(); ++i) {
      temp = x * (*i) + carry;
      ret.val.push_back(temp % 10000);
      carry = temp / 10000;
    }
    if (carry) {
      ret.val.push_back(carry);
    }
    return ret;
  }

  big operator/(int x) const {
    big ret;
    int temp, remainder = 0;
    for (auto i = val.rbegin(); i != val.rend(); ++i) {
      // from high to low
      temp = remainder * 10000 + (*i);
      ret.val.push_front(temp / x);
      remainder = temp % x;
    }
    for (auto i = ret.val.rbegin(); i != ret.val.rend(); ++i) {
      if (*i) break;
      ret.val.pop_back();
    }
    return ret;
  }

  int operator%(int x) const {
    int temp, remainder = 0;
    for (auto i = val.rbegin(); i != val.rend(); ++i) {
      temp = remainder * 10000 + (*i);
      remainder = temp % x;
    }
    return remainder;
  }
};
// }
int main(int argc, const char* argv[]) {
  int m, n;
  int temp;
  string x;
  string s;
  big value, base;

  while (cin >> m >> n) {
    cin >> x;
    s.clear();
    value.set(0);
    base.set(1);
    for (auto i = x.rbegin(); i != x.rend(); ++i) {
      if (isdigit(*i)) {
        temp = *i - '0';
      } else if (isupper(*i)) {
        temp = *i - 'A' + 10;
      } else {
        cout << "input error:\t" << *i << endl;
      }
      value = value + base * temp;
      base = base * m;
    }
    do {
      temp = value % n;
      if (temp < 10) {
        s.push_back(temp + '0');
      } else {
        s.push_back(temp - 10 + 'a');
      }
      value = value / n;
    } while (!value.empty());
    for (auto i = s.rbegin(); i != s.rend(); ++i) cout << *i;
    cout << endl;
  }

  return 0;
}
