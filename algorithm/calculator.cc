#include <iomanip>
#include <iostream>
#include <stack>
#include <string>
using namespace std;

double fun(double num_1, double num_2, char str) {
  if ('*' == str) return num_1 * num_2;
  if ('/' == str) return num_2 / num_1;
  if ('+' == str) return num_1 + num_2;
  if ('-' == str) return num_2 - num_1;
  return 0;
}

double calculate(string s) {
  stack<double> num;
  stack<char> str;
  for (int i = 0; i != s.size(); ++i) {
    // blank
    if (' ' == s[i]) continue;
    // number
    if (s[i] <= '9' && s[i] >= '0') {
      int temp = s[i] - '0';
      int j;
      for (j = i + 1; j != s.size() && '0' <= s[j] && s[j] <= '9'; ++j)
        temp = temp * 10 + (s[j] - '0');
      i = j - 1;
      num.push(temp);
    } else {
      // operation
      if (str.empty()) {
        str.push(s[i]);
      } else {
        //若是存运算符的栈非空，那么就需要和之前存入的运算符比较优先级
        char pre = str.top();
        if (('+' == pre || '-' == pre) && ('*' == s[i] || '/' == s[i])) {
          // pre<sign，继续压入
          str.push(s[i]);
        } else {
          // pre>=sign，取出运算
          str.pop();
          double num_1 = num.top();
          num.pop();
          double num_2 = num.top();
          num.pop();
          num.push(fun(num_1, num_2, pre));
          //运算之后，仍然会存在平级，即同为加减级，再运算一次
          // if (!str.empty() && ('+' == s[i] || '-' == s[i])) {
          //   char sign = str.top();
          //   str.pop();
          //   double num_1 = num.top();
          //   num.pop();
          //   double num_2 = num.top();
          //   num.pop();
          //   num.push(fun(num_1, num_2, sign));
          // }
          str.push(s[i]);
        }
      }
    }
  }
  while (!str.empty()) {
    char sign = str.top();
    str.pop();
    double num_1 = num.top();
    num.pop();
    double num_2 = num.top();
    num.pop();
    num.push(fun(num_1, num_2, sign));
  }
  return num.top();
}

int main(int argc, const char* argv[]) {
  string exp;
  while (getline(cin, exp)) {
    cout << fixed << setprecision(3) << calculate(exp) << endl;
  }
  return 0;
}