#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

char monthName[13][20] = {"January",   "February", "March",    "April",
                          "May",       "June",     "July",     "August",
                          "September", "October",  "November", "December"};

char weekName[7][20] = {
    "Sunday",   "Monday", "Tuesday", "Wednesday",
    "Thursday", "Friday", "Saturday"};  //周名 每个周名对应下标0到6

int main() {
  int d, m, y, c;
  int w;
  char s[20];
  while (scanf("%d%s%2d%2d", &d, s, &c, &y) != EOF) {
    for (m = 0; m != 12; m++) {
      if (strcmp(s, monthName[m]) == 0) {
        break;  //将输入字符串与月名比较得出月数
      }
    }
    m++;
    w = 0;
    w += floor(c / 4.0) - 2 * c;
    w += floor(y / 4.0) + y;
    w += floor(26 * (m + 1) / 10);
    w += d - 1;
    cout << weekName[w % 7] << endl;
    //将计算后得出的下标用7对其取模,并
    //且保证其为非负数,则该下标即为答案所对应的下标,输出即可
  }
  return 0;
}