/*
 * @Description: Fibonacci
 * @Author: Chiale
 * @Date: 2019-01-20 19:51:50
 * @LastEditTime: 2019-08-17 20:10:47
 */

#pragma once
#define DEBUG

#include <iostream>
#include <stack>

using namespace std;

struct Node {
  long n;
  int tag;
};

// 相当于树的后序遍历
long fibonacci(long n) {
  stack<Node> S;
  Node w;
  long sum = 0;
  do {
    while (n > 1) {
      w.n = n;
      w.tag = 1;  // left
#ifdef DEBUG
      cout << "(" << n << "," << 1 << ")+" << endl;
#endif
      S.push(w);
      n--;
    }
    /* F(1) = 1, F(0) = 0 */
    sum += n;
    while (S.empty() == false) {
      w = S.top();
      S.pop();
#ifdef DEBUG
      cout << "(" << w.n << "," << w.tag << ")-" << endl;
#endif
      if (w.tag == 1) {  // 一直取，取到左转过的为止
        w.tag = 2;       // right;
#ifdef DEBUG
        cout << "(" << w.n << "," << 2 << ")+" << endl;
#endif
        S.push(w);
        n = w.n - 2;
        break;
      }
    }
  } while (S.empty() == false);
  return sum;
}

int main(int argc, const char *argv[]) {
  cout << fibonacci(4) << endl;
  return 0;
}