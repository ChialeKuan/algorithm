#include <cstddef>  // ptrdiff_t
#include <cstring>  // c语言的string
#include <iostream>
#include <string>
#include <typeinfo>
#include "util.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

typedef int *pint;

// 数组和指针更加静态，只有在强调速度时才使用
void fun1() {
  int a1[] = {1, 2, 3};
  int a2[5] = {1, 2, 3};
  string a3[5] = {"Chiale"};
  char a4[4] = "NIL";  // 末尾是一个 null
  const unsigned size = 10;
  int buff[size];

  for (int i : a1) cout << i;
  cout << endl;
  for (int i : a2) cout << i;
  cout << endl;
  for (string i : a3) cout << i;
  cout << endl;
  for (char i : a4) cout << i;
  cout << endl;
  for (size_t i = 0; i != size; i++) cout << buff[i];
  cout << endl;
}

// 指针
// 指向某种类型对象的复合数据类型
void fun2() {
  string s("Hello Chiale");
  string *sp1 = &s;
  void *sp2 = &s;  // 可以保存任何类型，但是支持的操作很有限
  void *sp3 = 0;   // 可以使用0来进行初始化
  info("deinference");
  cout << *sp1 << endl;
  info("assignment");
  *sp1 = "Bye Chiale";  // 修改指针指向的对象
  cout << s << endl;

  // pointer
  int a1 = 1;
  int a2 = 2;
  int *p1 = &a1;
  int *p2 = &a2;
  p1 = p2;  // p1 指向了 a2
  cout << a1 << a2 << *p1 << *p2 << endl;
  // reference
  int &r1 = a1;
  int &r2 = a2;
  r1 = r2;  // a1 的值被修改了
  cout << a1 << a2 << r1 << r2 << endl;
  info("type");
  cout << typeid(p1).name() << "\t" << typeid(r1).name() << endl;
  double f = 1.0;

  cout << typeid(f).name() << endl;

  const int buff_size = 7;
  int a3[buff_size] = {0, 1, 2, 3, 4, 5};
  int *p3 = a3 + 3;
  cout << *p3 << endl;
  ptrdiff_t diff = a3 - p3;
  cout << diff << endl;

  int *begin = a3;
  int *end = a3 + buff_size;
  for (; begin != end; begin++) cout << *begin;
  cout << endl;

  // 指向const的指针
  const int a4 = 10;
  const int *p4 = &a4;  // 不能修改对象的值，可以修改指向的对象
  // const指针
  int a5 = 0;
  int *const p5 = &a5;
  // 指向const的const指针
  const int *const p6 = &a4;
  // 实际上是const指针
  const pint p7 = &a5;
}

void fun3() {
  const char *cp = "Chiale";  // 结尾是null，作为setinel
  while (*cp) {
    cout << *cp;
    ++cp;
  }
  cout << endl;

  char a1[] = "Chiale";
  cout << "strlen:" << strlen(a1) << endl;
  char a2[7];
  strncpy(a2, a1, 7);
  cout << a2 << endl;

  // 堆，用于存放动态分配的对象
  // 动态数组
  int *a3 = new int[10];
  const int *a4 = new const int[10]();  // 初始化过了
  cout << a3[0] << endl;
  cout << a4[0] << endl;
  delete[] a3;  // 少了方括号可能会产生内存泄漏
  delete[] a4;

  // 如何兼容
  string a5 = "Chiale";
  const char *a6 = a5.c_str();
  cout << a6 << endl;
}

// 多维数组
void fun4() {
  int a1[2][2] = {0, 1, 2, 3};
  int a2[2][2] = {{0, 1}, {2, 3}};

  int(*p1)[2] = a1;  // 数组指针
  cout << **p1 << endl;
  for (p1 = a1; p1 != a1 + 2; p1++)
    for (int *q = *p1; q != *p1 + 2; q++) cout << *q << endl;
}

int main(int argc, const char *argv[]) {
  title("4.1 array");
  fun1();
  title("4.2 pointer");
  fun2();
  return 0;
}
