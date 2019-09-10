/*
 * @Description: primer plus chapter 1 start
 * @Author: Chiale
 * @Date: 2019-04-14 14:35:26
 * @LastEditTime: 2019-08-20 16:20:23
 */

#include "ch1.h"
#include <iostream>
#include "util.h"

void fun2() {
  int var1;
  std::cout << "输入一个数字，endl 可以用来清空缓存" << std::endl;
  std::cin >> var1;
  std::cout << var1 << std::endl;
}

void fun3() {
  // 变量，注释在代码上方
  // 嵌套的代码注释最好还是用双斜线
  int output = 10;
  // 以下的注释是不合法的
  // std::cout << /* "*/" */;
  std::cout << output << std::endl;
}

void fun4() {
  int sum = 0;
  int value;
  std::cout << "Input the number to be add up" << std::endl;
  info("Ctrl+Z / Cmd+D could work as the end signal");
  while (std::cin >> value) {
    // 输入 Ctrl+Z 结束循环
    sum += value;
  }
  std::cout << "The sum is " << sum << std::endl;
}

extern const int const_int2;

void fun5() { std::cout << const_int2 << std::endl; }

int main(int argc, const char* argv[]) {
  title("1.2 输入输出");
  fun2();
  title("1.3 注释");
  fun3();
  title("1.4 控制流");
  fun4();
  title("1.5 声明和定义");

  fun5();
  return 0;
}