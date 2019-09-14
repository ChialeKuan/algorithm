/*
 * @Description: pta 1010
 * @Author: Chiale
 * @Date: 2019-09-10 09:24:59
 * @LastEditTime: 2019-09-10 09:25:19
 */

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <stdlib.h>
#include <string>
#include <vector>

using namespace std;

long long to_num(const string &b, long long radix) {
  long long res = 0;
  auto lenb = b.size() - 1;
  for (int i = 0; i < b.size(); i++) {
    if (isdigit(b[i])) {
      res += (b[i] - '0') * pow(radix, lenb--);
    } else {
      res += (b[i] - 'a' + 10) * pow(radix, lenb--);
    }

    if (res < 0)
      return -1;
  }
  return res;
}

int main() {
  // improve the efficiency of cin
  ios::sync_with_stdio(false);
  string a, b;
  int tag;
  long long radix;
  cin >> a >> b >> tag >> radix;

  if (a == b) {
    cout << radix << endl;
    return 0;
  }

  if (tag == 2) {
    swap(a, b);
  }

  // number
  long long tmp = 0;
  auto len = a.size() - 1;
  for (auto i = 0; i < a.size(); i++) {
    if (a[i] >= '0' && a[i] <= '9') {
      tmp += (a[i] - '0') * pow(radix, len--);
    } else {
      tmp += (a[i] - 'a' + 10) * pow(radix, len--);
    }
  }
  // the largest character
  int Max = -1;
  int mm;
  for (auto i = 0; i < b.size(); i++) {
    if (b[i] >= '0' && b[i] <= '9') {
      mm = b[i] - '0';
    } else {
      mm = b[i] - 'a' + 10;
    }
    Max = max(Max, mm);
  }

  bool flag = false;
  //就是这里关于边界的问题，真的要把我搞死了
  // 这里的第一个样例就是 就应该是他的值小于其的边界，正好就是 Max 等于2的时候。
  //将两个边界值给弄清楚。
  long long low = Max + 1;
  long long high = max(tmp, low);
  long long mid = -1;
  while (low <= high) {
    mid = (low + high) >> 1;
    long long tp = to_num(b, mid);
    if (tp == -1 || tp > tmp) {
      high = mid - 1;
    } else if (tp < tmp)
      low = mid + 1;
    else if (tp == tmp) {
      flag = true;

      break;
    }
  }

  /*
   这里其实是一个顺序查找的过程，但是由于循环次数太多，所以必须进行二分优化。

   for (ans = Max; ans <= tmp; ans++) {
   res = 0;
   for (int i = 0; i < b.size();i++) {
   if (b[i] >= '0' && b[i] <='9') {
   res += (b[i] - '0') * pow(ans,lenb--);
   }
   else {
   res += (b[i] - 'a' + 10) * pow(ans,lenb--);
   }
   }

   if (tmp == res) {
   flag = true;
   break;
   }

   }*/

  if (flag == true && mid >= 1)
    cout << mid << endl;
  else
    cout << "Impossible" << endl;

  return 0;
}
