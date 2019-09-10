#include <algorithm>
#include <iostream>
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

int main() {
  Date tmp;
  int cnt = 0;  //天数计数
  tmp.Day = 1;
  tmp.Month = 1;
  tmp.Year = 0;  //初始化日期类对象为0年1月1日
  while (tmp.Year != 5001) {
    ////日期不超过5000年
    buf[tmp.Year][tmp.Month][tmp.Day] = cnt;
    tmp.nextDay();  //计算下一天日期
    cnt++;  //计数器累加，每经过一天计数器即+1，代表与原点日期的间隔又增加一天
  }
  int d1, m1, y1;
  int d2, m2, y2;
  while (scanf("%4d%2d%2d", &y1, &m1, &d1) != EOF) {
    scanf("%4d%2d%2d", &y2, &m2, &d2);  //读入要计算的两个日期
    cout << abs(buf[y2][m2][d2] - buf[y1][m1][d1] + 1) << endl;
  }
  return 0;
}