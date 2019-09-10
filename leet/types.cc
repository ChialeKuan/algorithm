#include "algorithms.h"
#include <cassert>
#include <iostream>
#include <list>
#include <map>
#include <unordered_map>

using namespace std;

void test_map() {
  std::map<std::string, int> m;
  m["hello"] = 23;
  // check if key is present
  if (m.find("hello") != m.end())
    std::cout << "map contains key hello!\n";
}

void test_list() {
  list<int> li = {1, 2, 3, 7, 9};
  for (list<int>::iterator i = li.begin(); i != li.end(); i++)
    if ((*i) == 7) {
      li.erase(i);
      break;
    }
  for (list<int>::iterator i = li.begin(); i != li.end(); i++)
    cout << (*i) << " ";
  cout << endl;
}

class Hashtable {
  std::unordered_map<const void *, const void *> htmap;

public:
  void put(const void *key, const void *value) { htmap[key] = value; }

  const void *get(const void *key) { return htmap[key]; }
};

void test_unordered_map() {
  Hashtable ht;
  ht.put("Bob", "Dylan");
  int one = 1;
  ht.put("one", &one);
  cout << (char *)ht.get("Bob") << endl;
  cout << *(int *)ht.get("one") << endl;
}
void type_test() { test_unordered_map(); }
