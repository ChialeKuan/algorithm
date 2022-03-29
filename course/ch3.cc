/*
 * @Description: container
 * @Author: Chiale
 * @Date: 2019-03-26 19:51:52
 * @LastEditTime: 2019-09-05 16:55:13
 */
#include <bitset>
#include <cctype>  // cpp 的 ctype.h，使用了 std
#include <iostream>
#include <string>
#include <vector>
#include "primer.h"
#include "util.h"

// using
using std::bitset;
using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::string;
using std::vector;

void read_one() {
  // 读取到空白字符为止
  string a1;
  cout << "Input Hello World\n";
  cin >> a1;
  cout << a1;
}

void read_many() {
  string a1;
  while (cin >> a1) cout << a1 << endl;
}

void read_line() {
  // 换行符并不会被存储
  string a1;
  while (getline(cin, a1)) cout << a1 << endl;
}

void cctype_ops() {
  // 非零即为 true，数值是无意义的 int
  char a1 = 'A';
  char a2 = '0';
  cout << "letter:" << isalpha(a1) << endl;
  cout << "number:" << isdigit(a2) << endl;
  cout << "letter or number:" << isalnum(a2) << endl;
  cout << "control:" << iscntrl(a2) << endl;
  cout << "printable:" << isprint(a1) << endl;
  cout << "printable, not space:" << isgraph(a1) << endl;
  cout << "lowercase:" << islower(a1) << endl;
  cout << "uppercase:" << isupper(tolower(a1)) << endl;
  cout << "punctuation:" << ispunct(',') << endl;
  cout << "blank:" << isspace(' ') << endl;
  cout << "hexidecimal:" << isxdigit(a1) << endl;
}

void fun2() {
  string a1;
  // 初始化的三种方法
  string a2("Chiale");
  string a3(a2);
  string a4(10, '*');
  string a5;
  a5 += a2;
  cout << a2 << endl;
  cout << a3 << endl;
  cout << a4 << endl;
  cout << a5 << endl;

  // read_one();
  // read_many();
  // read_line();

  string::size_type b1 = a2.size();

  cout << "empty:\t" << a1.empty() << endl;
  cout << "size:\t" << b1 << endl;
  cout << "+:\t" << a4 + a2 << endl;
  cout << "==:\t" << (a2 == a3) << endl;
  cout << "<:\t" << (a2 < a4) << endl;

  cout << "iteration:";
  for (string::size_type i = 0; i < a2.size(); i++) cout << a2[i];

  string c1 = "Chiale Kuan";
  cout << "find a:" << c1.find("a") << endl;
  cout << "find b == npos:" << (c1.find("b") == string::npos) << endl;

  // fun fact
  cout << "false == 0:" << (false == 0) << endl;
  cout << "npos == -1:" << (string::npos == -1) << endl;
}

class text {
 private:
  string str;

 public:
  text(string s) : str(s) {}
  void show() const { cout << str << endl; }
};

void fun3() {
  // vector 是一个模板
  vector<int> a1;

  vector<int> a2(10, 1);  // 10 个 1
  for (auto x : a2) cout << x;
  cout << endl;

  vector<int> a3(10);  // 使用默认构造函数，默认为0

  vector<int> a4(a3);  // 复制构造函数

  const size_t size = 10;
  int a5_arr[size] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  vector<int> a5(a5_arr, a5_arr + size);  //

  // size 可能会动态变化
  // size 函数是 inline 函数
  info("use index to do the iteration");
  for (vector<int>::size_type i = 0; i != a5.size(); i++) cout << a5[i];
  cout << endl;

  info("use iterator to do the iteration");
  vector<int>::iterator it = a5.begin();
  while (it != a5.end()) cout << *it++;  //*(it++)
  cout << endl;

  cout << "empty:" << a2.empty() << endl;
  cout << "size:" << a2.size() << endl;
  cout << "==:" << (a1 == a2) << endl;

  vector<text> b1;
  b1.emplace_back("Chiale");
  b1.push_back(text("Kuan"));
  b1.front().show();
  b1.back().show();
}

// 迭代器适用于所有的容器
// 迭代器的相等，即其指向的变量相同
void fun4() {
  vector<int> a1(10);
  // end 为超出模板迭代器，指向最后一个元素的下一个，作为哨兵
  int i = 1;
  info("iterator");
  for (vector<int>::iterator iter = a1.begin(); iter != a1.end(); iter++) {
    // deference operator
    cout << *iter << " ";
    *iter = i;
    i *= 2;
  }
  cout << endl;

  info("const_iterator");
  for (vector<int>::const_iterator iter = a1.begin(); iter != a1.end();
       iter += 1) {
    // 迭代器可以进行算数操作
    // 不能对指向的元素进行赋值
    cout << *iter << " ";
  }
  cout << endl;

  vector<int>::iterator b1;
  vector<int>::iterator b2;
  for (vector<int>::iterator iter = a1.begin(); iter != a1.end(); iter++) {
    if (*iter == 32) b1 = iter;
    if (*iter == 256) b2 = iter;
  }
  // signed vector<int>::size_type
  cout << "the difference(256-32):" << b2 - b1 << endl;
  // 注意不能使用 end()
  vector<int>::iterator b3 = a1.begin() + a1.size() / 2;
  cout << "the middle:" << *b3 << endl;
}

void fun5() {
  // 0 位是最低位
  bitset<2> a1;
  bitset<8> a2(0xc);  // 前部填0，太大了会截断
  bitset<32> a3("1100");
  cout << a1 << endl;
  cout << a2 << endl;
  cout << a3 << endl;

  string b1("010010001000010000010000001");
  bitset<7> a4(b1, 1, 7);  // 使用子串，子串的序列是从左到右的
  bitset<7> a5(b1, b1.size() - 7);
  cout << a4 << endl;
  cout << a5 << endl;

  cout << "any 1:" << a1.any() << endl;
  cout << "no 1:" << a1.none() << endl;
  cout << "count of 1:" << a2.count() << endl;
  cout << "size:" << a2.size() << endl;
  cout << "a2[3]:" << a2[3] << endl;
  cout << "test a2[3]:\t" << a2.test(3) << endl;
  cout << "set all of a1:\t" << a1.set() << " " << a1 << endl;
  cout << "reset all of a1:" << a1.reset() << " " << a1 << endl;
  cout << "set 5 of a2:\t" << a2.set(5) << " " << a2 << endl;
  cout << "reset 5 of a2:\t" << a2.reset(5) << " " << a2 << endl;
  cout << "flip all of a2:\t" << a2.flip() << " " << a2 << endl;
  cout << "flip 5 of a2:\t" << a2.flip(5) << " " << a2 << endl;

  unsigned long c1 = a2.to_ulong();
  cout << "to ulong:\t" << c1 << endl;
}

int main(int argc, const char* argv[]) {
  title("3.2 string");
  fun2();
  title("3.3 vector");
  fun3();
  title("3.4 iterator");
  fun4();
  title("3.5 bitset");
  fun5();
}