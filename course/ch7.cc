#include <iostream>
#include <string>
#include <vector>
#include "primer.h"
#include "util.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int gcd(int v1, int v2) {
  while (v2) {
    int temp = v2;
    v2 = v1 % v2;
    v1 = temp;
  }
  return v1;
}

void fun1() {
  cout << gcd(100, 234) << endl;
  cout << gcd(234, 100) << endl;
}

void use_ptr(int* p) {
  // 使用指针来修改值
  *p = 0;
}

// 如果直接传递一个非引用vector过来，会复制每一个元素
vector<int>::const_iterator find_val(vector<int>::const_iterator beg,
                                     vector<int>::const_iterator end, int value,
                                     vector<int>::size_type& occurs) {
  // & modify the argument
  // const & void copying the argument
  vector<int>::const_iterator res_iter = end;
  occurs = 0;
  for (; beg != end; ++beg) {
    if (*beg == value) {
      if (res_iter == end) {
        // first occurence
        res_iter = beg;
      }
      ++occurs;
    }
  }
  return res_iter;
}

void ptr_swap(int*& v1, int*& v2) {
  // refernce to a pointer
  int* tmp = v1;
  v1 = v2;
  v2 = tmp;
}

// 引用会检查维度是否匹配，否则只会当成一个指针
// 还可以使用类似 vector 的方式检查越界
// 或者把维度写到参数里面
void print_values(int (&arr)[5]) {
  for (size_t i = 0; i < 5; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}

void fun2() {
  info("use_ptr");
  int a = 7;
  int* ap = &a;
  use_ptr(ap);
  cout << a << endl;

  info("find_val");
  vector<int> b = {1, 3, 5, 7, 9, 11, 13, 15, 7, 2, 3};
  // get value in parameter
  vector<int>::size_type bn;
  vector<int>::const_iterator bi = find_val(b.begin(), b.end(), 7, bn);
  cout << bn << " " << *bi << endl;

  info("ptr_swap");
  int c1 = 1;
  int c2 = 2;
  int* c1p = &c1;
  int* c2p = &c2;
  ptr_swap(c1p, c2p);
  cout << *c1p << " " << *c2p << endl;

  info("print_values");
  int d[5] = {1, 1, 2, 3, 5};
  print_values(d);
}

// nonreference
string make_plural(size_t ctr, const string& word, const string& ending) {
  // 返回的是一个副本，或者是一个未命名的临时对象
  return (ctr == 1) ? word : word + ending;
}

// reference
// 不能返回局部变量的引用
void fun3() {
  /* newline */
  cout << make_plural(2, "chiale", "s") << endl;
}

void fun4(int def) {
  // 通常应该把默认实参放在声明中
  // 否则只有在改源文件中调用该函数时，默认实参才是有效的
  cout << def << endl;
}

int get_power(int x) {
  // 自动对象，生存期是函数块
  // 形参也是自动对象
  return x * x;
}

int count_calls() {
  // 静态局部对象，生存期是整个程序
  static size_t ctr = 0;
  return ++ctr;
}

void ch75() {
  cout << get_power(10) << endl;
  cout << count_calls() << endl;
  cout << count_calls() << endl;
  cout << count_calls() << endl;
  cout << count_calls() << endl;
}

void ch76() { cout << compare(1, 2) << endl; }

// main 不能重载
// 返回值不影响重载
// typedef 不影响重载
// const 不影响非引用形参的重载
// int 不能传递给 enum 进行重载

void f1(Tokens x) { cout << "enum: " << x << endl; }
void f1(int x) { cout << "int: " << x << endl; }

void ch78() {
  f1(100);
  f1(INLINE);
}

bool compare(const string& x, const string& y) { return x.size() < y.size(); }

typedef bool (*cmp_fun)(const string&, const string&);

bool (*ff(int x))(const string&, const string&) {
  if (x == 1) return compare;
  return 0;
}
void ch79() {
  // bool (*pf)(const string&, const string&);
  cmp_fun pf1 = compare;
  // implicit dereference
  cout << pf1("Chiale", "Kuan") << endl;
  // explicit dereference
  cout << (*pf1)("Kuan", "Chiale") << endl;
  // complicated function
  cout << ff(1)("Hi", "haha") << endl;
}

int main(int argc, const char* argv[]) {
  title("declaration");
  fun1();
  title("argument passing");
  fun2();
  title("return");
  fun3();
  title("function declaration");
  fun4(12);
  //   void ch75();             // local objects
  //   void ch76();             // inline
  //   void ch78();             // overload
  //   void ch79();             // pointer to function
  return 0;
}