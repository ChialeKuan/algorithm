/*
 * @Description: PAT 1004
 * @Author: Chiale
 * @Date: 2019-09-09 10:05:22
 * @LastEditTime: 2019-09-09 10:07:08
 */

#include <iostream>
#include <vector>

#define INF 0x7fffffff

using namespace std;

struct Edge {
  int to;
  int cost;
};

struct Node {
  vector<Edge> table;
  int t;
  bool mark;
  int n;
};

int min_time_cnt;
int min_time_max_n;
int min_time;
int n, m, c1, c2;
vector<Node> nodes;

void DFS(int x, int t, int member) {
  if (x == c2) {
    member += nodes[c2].n;
    if (t < min_time) {
      min_time = t;
      min_time_cnt = 1;
      min_time_max_n = member;
    } else if (t == min_time) {
      min_time_cnt++;
      if (member > min_time_max_n) min_time_max_n = member;
    }
    return;
  }

  for (auto i : nodes[x].table) {
    if (nodes[x].mark == false) {
      nodes[x].mark = true;
      DFS(i.to, t + i.cost, member + nodes[x].n);
      nodes[x].mark = false;
    }
  }
}

int main() {
  Edge edge;
  Node node;
  min_time = INF;
  min_time_max_n = 0;
  cin >> n >> m >> c1 >> c2;

  node.t = INF;
  node.mark = false;
  for (int i = 0; i != n; ++i) {
    cin >> node.n;
    nodes.push_back(node);
  }
  int a, b, l;
  for (int i = 0; i != m; ++i) {
    cin >> a >> b >> l;
    edge.cost = l;
    edge.to = b;
    nodes[a].table.push_back(edge);
    edge.to = a;
    nodes[b].table.push_back(edge);
  }

  //    nodes[c1].mark = true;
  //    for (auto i:nodes[c1].table) {
  //        nodes[i.to].t = i.cost;
  //    }
  //
  //    for (int i = 1; i != n; ++i) {
  //        int opt = c1;
  //        int dist = INF;
  //        for (int i = 0; i != n; ++i) {
  //            if (nodes[i].mark == false && nodes[i].t < dist) {
  //                opt = i;
  //                dist = nodes[i].t;
  //            }
  //        }
  //        nodes[opt].mark = true;
  //        for (auto i:nodes[opt].table) {
  //            if (dist + i.cost < nodes[i.to].t) nodes[i.to].t = dist +
  //            i.cost;
  //        }
  //    }

  DFS(c1, 0, 0);
  cout << min_time_cnt << " " << min_time_max_n << endl;
}
