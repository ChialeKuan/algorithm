/*
 * @Description: pta 1006
 * @Author: Chiale
 * @Date: 2019-09-09 13:08:43
 * @LastEditTime: 2019-09-09 13:08:44
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Time {
  int h, m, s;
  bool operator<(const Time& x) const {
    if (h < x.h) return true;
    if (h > x.h) return false;
    if (m < x.m) return true;
    if (m > x.m) return false;
    if (s < x.s) return true;
    return false;
  }
};

struct Course {
  char name[15];
  Time begin, end;
};

bool cmp_1(const Course& a, const Course& b) { return a.begin < b.begin; }

bool cmp_2(const Course& a, const Course& b) { return a.end < b.end; }

int main() {
  int n;
  while (cin >> n) {
    Course course;

    vector<Course> buf;
    buf.clear();
    for (int i = 0; i != n; ++i) {
      scanf("%s %d:%d:%d %d:%d:%d", course.name, &course.begin.h,
            &course.begin.m, &course.begin.s, &course.end.h, &course.end.m,
            &course.end.s);
      buf.push_back(course);
    }
    sort(buf.begin(), buf.end(), cmp_1);
    cout << buf[0].name << " ";
    sort(buf.begin(), buf.end(), cmp_2);
    cout << buf[n - 1].name << endl;
  }
}
