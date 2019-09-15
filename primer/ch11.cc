#include <algorithm>  // 泛型算法
#include <deque>
#include <fstream>
#include <iostream>
#include <iterator>
#include <list>
#include <numeric>  // 算术算法
#include <sstream>
#include <string>
#include <vector>
#include "primer.h"

constexpr auto MAX = 50;

using namespace std;

bool isShorter(const string& s1, const string& s2) {
  return s1.size() < s2.size();
}

bool longerthan6(const string& s) { return s.size() >= 6; }

void chB2() {
  // 只读
  vector<int> vec;
  for (int i = 1; i < MAX + 1; ++i) {
    vec.push_back(i);
  }
  int sum = accumulate(vec.begin(), vec.end(), 0);
  cout << sum << " == " << (1 + 50) * 50 / 2 << endl;

  vector<string> vec_str = {"Hello", " ", "Chiale", "!"};
  string connection = accumulate(vec_str.begin(), vec_str.end(), string(""));
  cout << connection << endl;

  size_t cnt = 0;
  // 这里类型不相同
  list<string> roster1 = {"Chiale", "Kuan", "Guan"};
  vector<string> roster2 = {"Kuan", "world", "Guan"};
  list<string>::iterator it = roster1.begin();
  // look in roster1 for any name also in roster2
  while ((it = find_first_of(it, roster1.end(), roster2.begin(),
                             roster2.end())) != roster1.end()) {
    cout << *it << " " << cnt << endl;
    ++cnt;
    // we got a match, increment it to look in the rest of roster1
    ++it;
  }
  cout << "Found " << cnt << " names on both rosters" << endl;

  // 写
  // 不安全
  fill_n(vec.begin(), 10, 0);
  fill(vec.begin() + 10, vec.end(), 1);
  for (auto x : vec) cout << x;
  cout << endl;

  vector<int> vec2;  // empty vector
  // ok: back_inserter creates an insert iterator that adds elements to vec
  fill_n(back_inserter(vec2), 10, 2);  // appends 10 elements to vec
  for (auto x : vec2) cout << x;
  cout << endl;

  vector<int> vec3;
  // 同样也有front_inserter
  // 效率更高的方式
  // vector<int> vec3(vec2.begin(), vec2.end());
  copy(vec2.begin(), vec2.end(), back_inserter(vec3));
  for (auto x : vec3) cout << x;
  cout << endl;

  replace(vec.begin(), vec.end(), 1, 0);
  for (auto x : vec) cout << x;
  cout << endl;

  vector<int> vec4;
  cout << "replace copy:";
  replace_copy(vec.begin(), vec.end(), back_inserter(vec4), 0, 1);
  for (auto x : vec4) cout << x;
  cout << endl;

  vector<string> words;
  istringstream stream("the quick red fox jumps over the slow red turtle");
  string a;
  while (stream >> a) {
    words.push_back(a);
  }
  sort(words.begin(), words.end());
  vector<string>::iterator end_unique = unique(words.begin(), words.end());
  // 算法一般不删，这里只是把重复的移到了后面
  words.erase(end_unique, words.end());

  for (auto x : words) cout << x << " ";
  cout << endl;

  stable_sort(words.begin(), words.end(), isShorter);
  vector<string>::size_type wc =
      count_if(words.begin(), words.end(), longerthan6);

  cout << wc << endl;
}

void build_vector() {
  istream_iterator<int> in_iter(cin);  // read ints from cin
  istream_iterator<int> eof;           // istream "end" iterator
  vector<int> vec(in_iter, eof);
  // 等同于
  // while (in_iter != eof)
  // increment advances the stream to the next value
  // dereference reads next value from the istream
  // vec.push_back(*in_iter++);

  for (int i : vec) cout << i << " ";
  cout << endl;
}

void write_zigzag() {
  // write one string per line to the standard output
  ostream_iterator<string> out_iter(cout, "\n");
  // read strings from standard input and the end iterator
  istream_iterator<string> in_iter(cin), eof;
  // read until eof and write what was read to the standard output
  while (in_iter != eof)
    // write value of in_iter to standard output
    // and then increment the iterator to get the next value from cin
    *out_iter++ = *in_iter++;
}

void write_sort() {
  istream_iterator<int> cin_it(cin);    // reads ints from cin
  istream_iterator<int> end_of_stream;  // end iterator value
  // initialize vec from the standard input:
  vector<int> vec(cin_it, end_of_stream);
  sort(vec.begin(), vec.end());

  // writes ints to cout using " " as the delimiter
  ostream_iterator<int> output(cout, " ");

  // write only the unique elements in vec to the standard output
  unique_copy(vec.begin(), vec.end(), output);
}

void chB3() {
  list<char> ilst = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};
  vector<char> ivec = {'2', '3', '4', '5', '6', '7', '1', '2', '3', '4'};

  // 在指定位置插入迭代器
  list<char>::iterator it = find(ilst.begin(), ilst.end(), 'B');
  // insert replaced copies of ivec at that point in ilst
  replace_copy(ivec.begin(), ivec.end(), inserter(ilst, it), '1', '0');
  for (char a : ilst) cout << a;
  cout << endl;

  // build_vector();
  // write_zigzag();
  // write_sort();
  vector<int> vec;
  for (vector<int>::size_type i = 0; i != 10; ++i)
    vec.push_back(i);  // elements are 0,1,2,...9
  // reverse iterator of vector from back to front
  vector<int>::reverse_iterator r_iter;
  for (r_iter = vec.rbegin();  // binds r_iter to last element
       r_iter != vec.rend();   // rend refers 1 before 1st element
       ++r_iter)               // decrements iterator one element
    cout << *r_iter << endl;   // prints 9,8,7,...0
}

void chB5() {
  list<int> a = {1, 2, 4, 8, 16, 32};
  list<int> b = {23, 45, 21, 7, 7, 1};
  list<int> c = {100, 200, 300};
  list<int> d = {400, 500, 600};
  ostream_iterator<int> output(cout, " ");

  a.reverse();
  copy(a.begin(), a.end(), output);
  cout << endl;

  a.merge(b);
  copy(a.begin(), a.end(), output);
  cout << endl;

  a.remove(1);
  copy(a.begin(), a.end(), output);
  cout << endl;

  a.sort();
  copy(a.begin(), a.end(), output);
  cout << endl;

  a.splice(a.begin(), c);
  copy(a.begin(), a.end(), output);
  cout << endl;
  copy(c.begin(), c.end(), output);
  cout << endl;

  a.splice(a.begin(), d, d.begin());
  copy(a.begin(), a.end(), output);
  cout << endl;
  copy(d.begin(), d.end(), output);
  cout << endl;

  a.unique();
  copy(a.begin(), a.end(), output);
  cout << endl;
}

void chB() { chB5(); }