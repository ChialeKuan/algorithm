#include <iostream>
#include <vector>
using namespace std;

int main(int argc, const char* argv[]) {
  vector<int> a;
  a.push_back(10);
  a.erase(a.begin());
  cout << a.size();
  return 0;
}