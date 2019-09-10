#include <iostream>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>
#include "util.h"

using namespace std;

// include utility
void fun1() {
  pair<string, int> a("管佳乐", 1997);
  cout << a.first << " " << a.second << endl;

  auto b = make_pair("Chiale", 1997);
  cout << b.first << " " << b.second << endl;

  // public
  a.first = "Chiale";
  cout << a.first << endl;
}

void count_letter(string s) {
  map<char, int> a;
  // 会自动从0开始很方便
  for (char c : s) {
    a[c]++;
  }
  for (map<char, int>::const_iterator iter = a.begin(); iter != a.end();
       ++iter) {
    cout << iter->first << "\t";
  }
  cout << endl;

  for (map<char, int>::const_iterator iter = a.begin(); iter != a.end();
       ++iter) {
    cout << iter->second << "\t";
  }
  cout << endl;
}

void fun3() {
  // 键必须要支持 <
  map<string, int> map_1;

  // key_type mapped_type value_type
  map<string, int>::value_type pair_1("Chiale", 1997);
  pair<const string, int> pair_2("Fudan", 1905);

  /* insertion */
  auto res = map_1.insert(pair_1);
  // map iterator
  cout << res.first->first << " ";
  cout << res.first->second << endl;
  // bool, successful or not
  cout << res.second << endl;

  auto ai = map_1.insert(map_1.begin(), pair_2);
  // pair
  cout << ai->first << " " << ai->second << endl;

  auto count = map_1.erase("Fudan");
  info("erase");
  cout << count << endl;

  // 下标也可以插入
  // 先查重，再给key赋值 0，再赋值1997
  map_1["Kuan"] = 1997;

  // 左值
  map_1["Chiale"] += 22;
  cout << map_1["Chiale"] << endl;

  // insert 已有的，不会有改变
  map_1.insert(make_pair("Now", 2019));
  map_1.insert(make_pair("Now", 2020));

  // 0 or 1
  info("count(\"Now\")");
  cout << map_1.count("Now") << endl;
  info("count(\"Then\")");
  cout << map_1.count("Then") << endl;

  auto d = map_1.find("Chiale");
  info("a.find(\"Chiale\")->second");
  cout << d->second << endl;

  info("Traversal");
  for (auto i : map_1) {
    cout << i.first << " " << i.second << endl;
  }

  count_letter(
      "gjkfadslffsadreuwqiorfjdsaklfjasdlkfadfrp10frreyebfadsjkfjkdals");
}

void fun4() {
  vector<int> ivec;
  for (vector<int>::size_type i = 0; i != 10; ++i) {
    ivec.push_back((int)i);
    ivec.push_back(int(i));  // duplicate copies of each number
  }
  // iset holds unique elements from ivec
  set<int> iset(ivec.begin(), ivec.end());
  iset.insert(ivec.begin(), ivec.end());
  cout << "ivec.size():\t" << ivec.size() << endl;  // prints 20
  cout << "iset.size():\t" << iset.size() << endl;  // prints 10

  iset.insert(10);

  info("*[iset.find(10)]");
  // 不可以使用下标
  auto a = iset.find(10);
  // 迭代器只可读
  if (a != iset.end()) cout << *a << endl;

  info("iset.count(10)");
  size_t count = iset.count(10);
  cout << count << endl;
}

void fun5() {
  multimap<string, string> authors;
  // adds first element with key Barth
  authors.insert(make_pair(string("Barth, John"), string("Sot-Weed Factor")));

  // ok: adds second element with key Barth
  authors.insert(
      make_pair(string("Barth, John"), string("Lost in the Funhouse")));

  info("Iteraion 1, iter = find(); ++iter;");
  multimap<string, string>::iterator iter = authors.find("Barth, John");
  multimap<string, string>::size_type entries = authors.count("Barth, John");

  for (auto cnt = 0; cnt != entries; ++cnt, ++iter) {
    cout << iter->second << endl;
  }

  info("Iteration 2, lowerbound != upperbound");
  auto beg = authors.lower_bound("Barth, John");
  auto end = authors.upper_bound("Barth, John");

  while (beg != end) {
    cout << beg->second << endl;
    ++beg;
  }

  info("Iteration 3, bounds in a range");
  auto range = authors.equal_range("Barth, John");
  while (range.first != range.second) {
    cout << range.first->second << endl;
    ++range.first;
  }

  cout << "Erase count: " << authors.erase("Barth, John") << endl;
}

int main(int argc, const char *argv[]) {
  title("10.1 pair");
  fun1();
  title("10.3 map, associative array");
  fun3();
  title("10.4 set");
  fun4();
  title("10.5 multimap, multiset");
  fun5();  //
  return 0;
}
