#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct E {
  string name;
  int age;
  int score;
};

bool cmp(E a, E b) {  //实现比较规则
  if (a.score != b.score) return a.score < b.score;
  if (a.name != b.name) return a.name < b.name;
  if (a.age != b.age) return a.age < b.age;
  return 0;
}

vector<E> buf;

int main() {
  E e;
  int n;
  while (cin >> n) {
    for (int i = 0; i < n; i++) {
      cin >> e.name >> e.age >> e.score;
      buf.push_back(e);
    }
    sort(buf.begin(), buf.end(), cmp);  //利用自己定义的规则对数组进行排序
    for (int i = 0; i < n; i++) {
      cout << buf[i].name << " " << buf[i].age << " " << buf[i].score << endl;
    }  //输出排序后结果
  }
  return 0;
}