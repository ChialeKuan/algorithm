#include <iostream>
#include <string>
#include <vector>
#include "util.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int get_value() {
  static int x = 0;
  return ++x;  // using prefix is better
}

int main(int argc, const char *argv[]) {
  title("static");
  int a;
  while ((a = get_value()) != 10) cout << a;
  cout << endl;

  vector<int> b(1, 1);
  vector<int> c(90, 11243341324);
  cout << "char:\t" << sizeof(char) << endl;
  cout << "short:\t" << sizeof(short) << endl;
  cout << "int:\t" << sizeof(int) << endl;
  cout << "long:\t" << sizeof(long) << endl;
  cout << "vector<int>:\t" << sizeof(b) << endl;
  cout << "large vector:\t" << sizeof(c) << endl;

  title("tricky point");
  int x[10];
  int *p = x;
  cout << sizeof(x) / sizeof(*x) << " = " << sizeof(x) << " / " << sizeof(*x)
       << endl;
  cout << sizeof(p) / sizeof(*p) << " = " << sizeof(p) << " / " << sizeof(*p)
       << endl;

  const int *pci = new const int(1024);
  cout << *pci << endl;
  delete pci;

  title("named casts");
  double dval = 10.5;
  int ival1 = 2;
  int ival2 = 2;
  ival1 *= dval;
  ival2 *= static_cast<int>(dval);
  cout << ival1 << endl;
  cout << ival2 << endl;

  int d1 = 65;
  int *ip = &d1;
  char *ipc1 = reinterpret_cast<char *>(ip);  // recommend
  char *ipc2 = (char *)
      ip;  // c style, can be equal to static, dynamic or reinterprete cast
  char d2 = char(d1);  // function style
  cout << *ip << endl;
  cout << *ipc1 << *ipc2 << endl << d2 << endl;
  return 0;
}
