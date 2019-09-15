#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

#define ISLEAP(x) x % 100 != 0 && x % 4 == 0 || x % 400 == 0 ? 1 : 0

using namespace std;

int dayOfMonth[13][2] = {
    0,  0,  31, 31, 28, 29, 31, 31, 30, 30, 31, 31, 30, 30,
    31, 31, 31, 31, 30, 30, 31, 31, 30, 30, 31, 31};  //预存每月的天数,注意二月配合宏定义作特殊处理

struct Date {
  ////日期类,方便日期的推移
  int Day;
  int Month;
  int Year;
  void nextDay() {  //计算下一天的日期
    Day++;
    if (Day > dayOfMonth[Month][ISLEAP(Year)]) {  //若日数超过了当月最大 日数
      Day = 1;
      Month++;           //进入下一月
      if (Month > 12) {  //月数超过12
        Month = 1;
        Year++;  //进入下一年
      }
    }
  }
};

int buf[5001][13][32];  //保存预处理的天数

vector<string> monthName = {"January",   "February", "March",    "April",
                            "May",       "June",     "July",     "August",
                            "September", "October",  "November", "December"};

vector<string> weekName = {"Sunday",   "Monday", "Tuesday", "Wednesday",
                           "Thursday", "Friday", "Saturday"};

int main() {
  Date tmp;
  int cnt = 0;
  tmp.Day = 1;
  tmp.Month = 1;
  tmp.Year = 0;
  while (tmp.Year != 3001) {
    buf[tmp.Year][tmp.Month][tmp.Day] = cnt;
    tmp.nextDay();
    cnt++;
  }  //以上与上题一致,预处理出每一天与原点日期的天数差
  int d, m, y;
  char s[20];
  while (scanf("%d%s%d", &d, s, &y) != EOF) {
    for (m = 0; m != 12; ++m) {
      if (s == monthName[m]) {
        break;  //将输入字符串与月名比较得出月数
      }
    }
    m++;
    int days = buf[y][m][d] - buf[1997][3][23];
    //计算给定日期与今日日期的 天数间隔(注意可能为负)
    cout << weekName[(days % 7 + 7) % 7] << endl;
    //将计算后得出的下标用7对其取模,并
    //且保证其为非负数,则该下标即为答案所对应的下标,输出即可
  }
  return 0;
}