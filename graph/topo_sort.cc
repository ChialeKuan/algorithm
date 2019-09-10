#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Node {
  // 实际的实现不需要入边，只需要入度就可以了
  vector<int> in;
  vector<int> out;
  bool mark;
};

bool allMark(const vector<Node> &x) {
  for (auto i : x) {
    if (i.mark == false) return false;
  }
  return true;
}

bool hasHead(const vector<Node> &x) {
  for (auto i : x) {
    if (!i.mark && i.in.empty()) return true;
  }
  return false;
}

int main(int argc, const char *argv[]) {
  int n, m;
  int a, b;
  Node node;
  vector<Node> nodes;

  while (cin >> n >> m) {
    nodes.clear();
    nodes.reserve(n);
    node.mark = false;
    for (int i = 0; i != n; ++i) {
      nodes.push_back(node);
    }

    bool cont = true;

    for (int i = 0; i != m; ++i) {
      cin >> a >> b;
      nodes[a].out.push_back(b);
      nodes[b].in.push_back(a);
    }
    while (cont) {
      for (int i = 0; i != n; ++i) {
        if (nodes[i].mark == false && nodes[i].in.empty()) {
          nodes[i].mark = true;
          for (int j : nodes[i].out) {
            for (auto k = nodes[j].in.begin(); k != nodes[j].in.end(); ++k) {
              if (*k == i) {
                nodes[j].in.erase(k);
                break;
              }
            }
          }
        }
        if (allMark(nodes)) {
          cont = false;
          cout << "Yes" << endl;
          break;
        } else if (!hasHead(nodes)) {
          cont = false;
          cout << "No" << endl;
          break;
        }
      }
    }
  }
  return 0;
}
