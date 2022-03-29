/*
 * @Description: variant and types
 * @Author: Chiale
 * @Date: 2019-05-08 18:57:42
 * @LastEditTime: 2019-08-20 16:20:30
 */

#include <iostream>
#include <string>
#include "util.h"

void fun1() {
  /* char */
  info("wchar_t 用于输出 ascii 之外的字符");
  // wchar_t my_surname[] = L"管";
  // std::wcout << my_surname << std::endl;

  /* int */
  // round
  // ch = 306 % 256;
  info("round, 306 % 256, -1 % 256");
  unsigned char ch = 306;
  std::cout << (int)ch << std::endl;
  ch = -1;
  std::cout << (int)ch << std::endl;

  /* float */
  // 一般来讲选double比较好，double速度可能比float还要快一点
  info("double 类型");
  long double ld = 3.1415926;
  std::cout << ld << std::endl;
}

void fun2() {
  info("integer and float");
  long a1 = 100000000UL;
  long double a2 = 3.1415926L;
  double a3 = 1e-3;
  std::cout << a1 << std::endl;
  std::cout << a2 << std::endl;
  std::cout << a3 << std::endl;

  info("boolean and char");
  bool b1 = false;
  wchar_t b2 = L'a';
  char b3 = '\63';   // oxtal escape
  char b4 = '\x41';  // hex escape
  std::cout << b1 << std::endl;
  std::cout << b2 << std::endl;
  std::cout << b3 << std::endl;
  std::cout << b4 << std::endl;

  info("string");
  std::cout << "My name"
               " is Chiale Kuan"
               " by using conncatenation"
            << std::endl;
  std::cout << "My name \
is Chiale Kuan \
by using formatting"
            << std::endl;
}

// c++ 是一种静态类型语言，在编译时进行检查
// 对象是内存中具有类型的区域
// 在函数体内必须要初始化，在函数体外内置类型会自动初始化
// 声明可以有多个，但是定义只能有一个
int global_int1;         // declare and define
extern int global_int2;  // declare and not define, so no storage is allocated
extern int global_int3 = 7;  // declare and define, despite the keyword extern

void fun3() {
  std::cout << "variable name" << std::endl;
  char _ = '7';
  int Int = 7;
  std::cout << _ << std::endl;
  std::cout << Int << std::endl;

  std::cout << "Initialization" << std::endl;
  // 直接初始化，而不是复制初始化
  int a1(7);
  std::cout << a1 << std::endl;

  std::string b1("Hi, direct initialization");
  std::string b2(7, '7');
  std::cout << b1 << std::endl;
  std::cout << b2 << std::endl;

  std::cout << 5 << std::endl;

  std::cout << "Declaration" << std::endl;
}

// 仍然是一个左值
// 必须在定义时初始化
const int const_int1 = 7;  // 即使在全局作用域，也不能被其他文件访问
extern const int const_int2 = 7;  // 可以被其他文件访问

void fun4() { std::cout << const_int1 << std::endl; }

// 引用即是对象的另一个名字
void fun5() {
  int a1 = 7;
  int &ref = a1;  // 引用必须初始化，而且必须用对象来初始化
  ref += 1;
  std::cout << a1 << std::endl;
  std::cout << ref << std::endl;

  const int a2 = 7;
  const int &const_ref1 = a2;  // 用来指向const 对象
  const int &const_ref2 = 7;   // 这里可以用右值来初始化
  std::cout << const_ref1 << std::endl;
  std::cout << const_ref2 << std::endl;
}

// typedef即是类型的另一个名字
typedef int my_type;
void ch26() {
  my_type a1 = 7;
  std::cout << a1 << std::endl;
}

void ch27() {
  // 默认以0开始
  enum open_modes { input = 10, output, append, remove };
  std::cout << append << std::endl;
  open_modes another = input;
  std::cout << another << std::endl;
}

struct item {
  // class 默认为 private, struct 默认为 public
  // 程序任何部分都可以访问
 public:
  //
 protected:
  // 只能由类的部分访问
 private:
  std::string isbn;
  unsigned units_sold;
  double revenue;
};

int main(int argc, const char *argv[]) {
  title("2.1 基本类型");
  fun1();
  title("2.2 变量");
  fun2();
  title("1.3 注释");
  fun3();
  title("1.4 控制流");
  fun4();
  title("1.5 声明和定义");
  fun5();
  return 0;
}