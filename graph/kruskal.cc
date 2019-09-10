/*
 * @Description: N 然后 N(N-1)/2 个 a 到 b 到距离
 * @Author: Chiale
 * @Date: 2019-09-06 13:16:36
 * @LastEditTime: 2019-09-06 13:32:29
 */

#include <algorithm>
#include <iostream>
#include <vector>
#define N 1000

using namespace std;
struct Edge {
  int a, b;
  int c;
  bool operator<(const Edge& x) const { return c < x.c; }
};

int tree[N];

int findRoot(int x) {
  if (tree[x] == -1) return x;
  int temp = findRoot(tree[x]);
  tree[x] = temp;
  return temp;
}

int main(int argc, const char* argv[]) {
  int ans;
  int n, m;
  int a, b;
  Edge e;
  vector<Edge> edges;

  while (cin >> n) {
    ans = 0;
    edges.clear();
    m = n * (n - 1) / 2;
    edges.reserve(m);

    for (int i = 1; i != n + 1; ++i) {
      tree[i] = -1;
    }
    for (int i = 0; i != m; ++i) {
      cin >> e.a >> e.b >> e.c;
      edges.push_back(e);
    }
    sort(edges.begin(), edges.end());
    for (auto i = edges.begin(); i != edges.end(); ++i) {
      a = findRoot(i->a);
      b = findRoot(i->b);
      if (a != b) {
        tree[a] = b;
        ans += i->c;
      }
    }
    cout << ans << endl;
  }

  return 0;
}