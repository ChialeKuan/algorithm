#include <algorithm>
#include <deque>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include "primer.h"

using std::cin;
using std::cout;
using std::dec;
using std::deque;
using std::endl;
using std::find;
using std::hex;
using std::list;
using std::priority_queue;
using std::queue;
using std::stack;
using std::string;
using std::vector;

void ch91() {
  // һ��ʹ�� vector
  // ��β��ɾ deque
  // �м���ɾ list

  // ���ʹ��Ĭ�Ϲ��캯�����������
  // ˳��������Ԫ����Ҫ���Ը��ƺ͸�ֵ
  // ����
  // IO�����ã�����ָ�룬��඼��������Ԫ��
  vector<int> a1(2, 7);
  list<int> a2;
  // ���������Ϳ��Բ�ͬ��Ԫ�ص�����Ҳֻ��Ҫ���ݼ���
  deque<int> a3(a1.begin(), a1.end());

  vector<int> b1(a1);

  vector<vector<int> > c;
  c.push_back(a1);
  c.push_back(b1);
  for (vector<int> i : c) {
    for (int j : i) {
      cout << j << " ";
    }
    cout << endl;
  }
}

void ch92() {
  // ֻ�� vector �� deque �ṩ��
  // +n, + iter, <
  deque<int> a;
  for (int i = 0; i < 10; i++) {
    a.push_back(i);
  }

  deque<int>::iterator b1 = a.begin();
  deque<int>::iterator mid = b1 + a.size() / 2;
  deque<int>::iterator b2 = a.end();
  cout << "b1<b2: " << (b1 < b2) << endl;
  cout << "b1-b2: " << (b1 - b2) << endl;
  cout << "mid: " << *mid << endl;
}

void print_deque(deque<int> a) {
  if (a.size() == 0) {
    cout << "NULL" << endl;
  } else {
    for (int i : a) cout << i << " ";
    cout << endl;
  }
}

void ch93() {
  // push �� insert
  // �����ܵ��µ�����ʧЧ
  // ��Ҫ�洢 end()��ÿ��ʹ�õ�ʱ�����¼���
  deque<int> a;
  for (int i = 0; i < 10; i++) {
    a.push_back(i);
  }

  // vector push_front
  vector<int> b;
  vector<int>::iterator bi;
  for (int i = 3; i < 10; i++) {
    bi = b.insert(bi, -i);
  }

  // list, deque
  a.push_front(-1);

  // ע������֮ǰ
  a.insert(a.begin(), -2);
  a.insert(a.begin(), 1, -3);
  a.insert(a.begin(), b.begin(), b.end());

  print_deque(a);

  // ����������ͬ��Ԫ��������ͬ�������Ƚ�
  // ������string�ıȽϷ���
  deque<int> c(a);
  cout << "a==c: " << (a == c) << endl;

  cout << "maxsize: " << hex << a.max_size() << dec << endl;
  cout << "empty: " << a.empty() << endl;

  a.resize(10);     // trancate to 10 elements
  a.resize(15, 0);  // append 0
  print_deque(a);

  // front �� back ��������
  // begin �� end ����Ԫ��
  deque<int>::reference ai = a.front();

  // at ��������
  // �±귵��Ԫ��
  // ���������� list
  cout << ai << " " << a[0] << " " << a.at(0) << endl;

  a.erase(a.begin());
  print_deque(a);

  a.pop_front();
  print_deque(a);

  a.pop_back();
  print_deque(a);

  deque<int>::iterator d = find(a.begin(), a.end(), -3);
  if (d != a.end()) a.erase(d);
  print_deque(a);

  // a.clear();
  a.erase(a.begin(), a.end());
  print_deque(a);

  // assign
  a.assign(10, 0);
  print_deque(a);

  // a = c;
  a.assign(c.begin(), c.end());
  print_deque(a);

  // ֻ�ǽ�����������Ҳ�����
  // ����ʱ��
  deque<int> e(10, 0);
  deque<int>::const_iterator ei = e.begin();
  a.swap(e);
  print_deque(a);
  print_deque(e);
  cout << *ei << endl;
}

class Point {
 public:
  Point() { cout << "C"; }
  Point(const Point& p) { cout << "V"; }
  ~Point() { cout << "D"; }
};

void ch94() {
  // ģ�����Ĺ���
  int cap = 0;
  while (cap < 100000) {
    int delta = cap / 2;
    if (delta < 1) delta = 1;
    cap += delta;
    cout << cap << endl;
  }

  Point test[20];
  cout << endl;
  vector<Point> arr;
  // ��ǰ������С
  // arr.reserve(20);
  for (int i = 0; i < 20; i++) {
    arr.push_back(test[i]);
    cout << " (" << arr.capacity() << ", " << arr.size() << ")" << endl;
  }
  cout << endl;
}

void ch96() {
  string s("Hiya!");
  string::iterator iter = s.begin();
  while (iter != s.end()) cout << *iter++;
}

class Compare {
 public:
  bool operator()(int x, int y) { return x > y; }
};

void ch97() {
  // stack Ĭ�ϻ��� deque��Ҳ���Ի��� vl
  // queue Ĭ�ϻ��� deque��Ҳ���Ի��� l
  // pq    Ĭ�ϻ��� vector��Ҳ���Ի��� d
  // ģ���б���ڶ��������ǻ��ڵ�����
  deque<int> a;
  for (int i = 0; i < 10; i++) {
    a.push_back(i);
  }
  stack<int> b(a);

  b.push(10);
  for (int i = 0; i < 11; i++) {
    cout << b.top() << " ";
    b.pop();
  }
  cout << endl;

  priority_queue<int> c(a.begin(), a.end());
  priority_queue<int, std::vector<int>, Compare> d;
  c.push(-3);
  c.push(12);
  c.push(-8);
  while (c.size()) {
    cout << c.top() << " ";
    d.push(c.top());
    c.pop();
  }
  cout << endl;

  while (d.size()) {
    cout << d.top() << " ";
    d.pop();
  }
  cout << endl;
}

void ch9() { ch97(); }
