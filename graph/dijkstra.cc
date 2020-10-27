#include <iostream>
#include <vector>
#define INF 0x7fffffff

using namespace std;

struct Edge {
    int next;
    int c;
};

struct Node {
    vector<Edge> table;
    bool mark;
    int last;
    int dist;
};

int main(int argc, const char *argv[]) {
    int a, b, c;
    int m, n;
    int opt;
    int dist;
    Edge e;
    vector<Node> nodes;
    vector<int> trace;

    while (cin >> n >> m) {
        nodes.clear();
        trace.clear();

        for (int i = 0; i != n; ++i) {
            Node n;
            n.mark = false;
            n.dist = INF;
            n.last = -1;
            nodes.push_back(n);
        }

        for (int i = 0; i != m; ++i) {
            cin >> a >> b >> c;
            --a;
            --b;
            // 注意两个方向
            e.c = c;
            e.next = b;
            nodes[a].table.push_back(e);
            e.next = a;
            nodes[b].table.push_back(e);
        }

        nodes[0].dist = 0;
        nodes[0].mark = true;
        opt = 0;
        for (int j = 0; j != n - 1; ++j) {
            dist = INF;
            // finding smallest
            for (int i = 0; i != n; ++i) {
                if (nodes[i].mark == false && nodes[i].dist < dist) {
                    opt = i;
                    dist = nodes[i].dist;  // forgot to update dist
                }
            }
            // update
            nodes[opt].mark = true;
            for (Edge i : nodes[opt].table) {
                if (nodes[i.next].mark == false &&
                    nodes[opt].dist + i.c < nodes[i.next].dist) {
                    nodes[i.next].dist = nodes[opt].dist + i.c;
                    nodes[i.next].last = opt;
                }
            }
        }
        int current = n - 1;
        cout << nodes[n - 1].dist << ":";
        do {
            trace.push_back(current + 1);
            current = nodes[current].last;
        } while (current != -1);
        for (auto i : trace) cout << i << ' ';
        cout << endl;
    }
    return 0;
}
