#include <iostream>
#include <vector>
#define MAX 1000000
using namespace std;

bool mark[MAX + 1];
vector<int> primes;

int main(int argc, const char* argv[]) {
  int n;
  primes.reserve(10000);
  bool first;

  for (__int128_t i = 2; i != MAX; ++i) {
    if (mark[i]) continue;
    primes.push_back(i);
    for (__int128_t j = i * i; j <= MAX; j += i) {
      // 这里不从 2i 开始
      mark[j] = true;
    }
  }
  while (cin >> n) {
    bool first = true;
    while (n > 1) {
      for (auto i = primes.begin(); i != primes.end(); ++i) {
        if (!(n % *i)) {
          n /= *i;
          if (first)
            first = false;
          else
            cout << "*";
          cout << *i;
          break;
        }
      }
    }
    cout << endl;
  }
  return 0;
}