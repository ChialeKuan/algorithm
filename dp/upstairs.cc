#include <iostream>
#define MAX 100
using namespace std;

__int64_t fib[MAX];
int main(int argc, const char* argv[]) {
  int n;
  fib[0] = 1;
  fib[1] = 1;
  for (int i = 2; i != MAX; ++i) {
    fib[i] = fib[i - 1] + fib[i - 2];
  }
  while (cin >> n) {
    cout << fib[n] << endl;
  }
  return 0;
}