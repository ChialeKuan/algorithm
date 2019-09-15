/*
 * @Description: 一个二分搜索，根据学号作为索引
 * @Author: Chiale
 * @Date: 2019-09-03 22:10:55
 * @LastEditTime: 2019-09-15 09:08:53
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Student {
  string no;
  string name;
  int age;
  string sex;
  bool operator<(const Student &A) const { return no < A.no; }
};

int main() {
  int n;
  Student st;
  vector<Student> record;

  int q;
  string no;
  int ans;
  int left, right, mid;
  while (cin >> n) {
    record.clear();
    for (int i = 0; i != n; ++i) {
      cin >> st.no >> st.name >> st.sex >> st.age;
      record.push_back(st);
    }
    sort(record.begin(), record.end());
    cin >> q;
    for (int i = 0; i != q; ++i) {
      cin >> no;
      ans = -1;
      left = 0;
      right = n - 1;
      while (left <= right) {
        mid = (left + right) / 2;
        if (record[mid].no == no) {
          ans = mid;
          break;
        } else if (record[mid].no < no) {
          left = mid + 1;
        } else {
          right = mid - 1;
        }
      }
      if (ans == -1) {
        cout << "No Answer!" << endl;
      } else {
        cout << record[ans].no << " " << record[ans].name << " "
             << record[ans].sex << " " << record[ans].age << endl;
      }
    }
  }
}