/*
 * @Description: pta 1004
 * @Author: Chiale
 * @Date: 2019-09-09 12:21:08
 * @LastEditTime: 2019-09-09 12:21:29
 */

#include <iostream>
#include <map>
#include <vector>
using namespace std;

struct Node {
  int level;
  int parent;
  vector<int> children;
};

vector<Node> nodes;

int get_level(int x) {
  if (nodes[x].level != -1) return nodes[x].level;
  int tmp = get_level(nodes[x].parent);
  nodes[x].level = tmp + 1;
  return tmp + 1;
}

int main() {
  int n, m;
  int id, num;
  int child;
  int tmp;

  cin >> n >> m;

  Node node;
  node.level = -1;
  node.parent = -1;

  nodes.reserve(n + 1);
  for (int i = 0; i != n + 1; ++i) {
    nodes.push_back(node);
  }

  for (int i = 0; i != m; ++i) {
    cin >> id >> num;
    for (int j = 0; j != num; ++j) {
      cin >> child;
      nodes[id].children.push_back(child);
      nodes[child].parent = id;
    }
  }

  nodes[1].level = 0;
  map<int, int> maps;
  for (int i = 1; i != nodes.size(); ++i) {
    tmp = get_level(i);
    if (nodes[i].children.empty()) {
      maps[tmp] += 1;
    } else {
      maps[tmp] += 0;
    }
  }
  bool start = true;
  for (auto i : maps) {
    if (start) {
      start = false;
    } else {
      cout << " ";
    }
    cout << i.second;
  }
  cout << endl;
}
