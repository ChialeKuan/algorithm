/*
 * @Description: max{k|n! % a^k == 0 && n! % a^(k+1) != 0
 * @Author: Chiale
 * @Date: 2019-09-05 15:44:06
 * @LastEditTime: 2019-09-05 16:47:21
 */

#include <iostream>
#include <vector>
#define MAX 1000000
using namespace std;

bool mark[MAX];

int main(int argc, const char* argv[]) {
  vector<int> primes;
  primes.reserve(MAX / 10);
  // cout << primes.capacity() << endl;

  for (int i = 2; i != MAX; ++i) {
    if (mark[i]) continue;
    mark[i] = true;
    primes.push_back(i);
    for (__uint64_t j = i * i; j < MAX; j += i) {
      mark[j] = true;
    }
  }

  vector<int> n_rec(primes.size());
  vector<int> a_rec(primes.size());

  int n, a;
  int t;
  int ans;
  while (cin >> n >> a) {
    ans = INT32_MAX;
    for (auto i : n_rec) i = 0;
    for (auto i : a_rec) i = 0;
    for (int i = 0; i != primes.size(); ++i) {
      // n_rec[i]= t/p+t/p^2+t/p^3+...
      t = n;
      n_rec[i] += t / primes[i];
      t = t / primes[i];
    }
    for (int i = 0; i != primes.size(); ++i) {
      while (a % primes[i] == 0) {
        a_rec[i]++;
        a /= primes[i];
      }
      if (a_rec[i] == 0) continue;
      if (n_rec[i] / a_rec[i] < ans) ans = n_rec[i] / a_rec[i];
    }
    cout << ans << endl;
  }

  return 0;
}