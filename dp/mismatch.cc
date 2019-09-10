#include <iostream>
#define MAX 20

using namespace std;
__int64_t F[MAX];

// _n is in box n
// n is in box x

// F[i-1] _n!=x
// F[i-2] _n==x

int main(int argc, const char* argv[]) {
  F[1] = 0;
  F[2] = 1;
  for (int i = 3; i != MAX; ++i) {
    F[i] = (i - 1) * (F[i - 1] + F[i - 2]);
  }
  int n;
  while (cin >> n) {
    cout << F[n] << endl;
  }
  return 0;
}