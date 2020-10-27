#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Node {
    // 实际的实现不需要入边，只需要入度就可以了
    int in;
    vector<int> out;
    bool mark;
};

bool check_topo_2(vector<Node> &nodes) {
    queue<int> head;
    int cnt = 0;
    for (int i = 0; i != nodes.size(); ++i) {
        for (int j = 0; j != nodes.size(); ++j) {
            if (nodes[j].mark == false && nodes[j].in == 0) {
                nodes[j].mark = true;
                head.push(j);
                ++cnt;
                for (auto k : nodes[j].out) {
                    nodes[k].in--;
                }
            }
        }
        if (head.empty()) break;
    }
    if (cnt == nodes.size()) return true;
    return false;
}

bool check_topo(vector<Node> &nodes) {
    queue<int> head;
    int cnt = 0;
    int tmp;
    for (int i = 0; i != nodes.size(); ++i) {
        if (nodes[i].in == 0) head.push(i);
    }
    while (!head.empty()) {
        tmp = head.front();
        head.pop();
        ++cnt;
        for (auto i : nodes[tmp].out) {
            nodes[i].in--;
            if (nodes[i].in == 0) {
                head.push(i);
            }
        }
    }
    return cnt == nodes.size();
}

int main(int argc, const char *argv[]) {
    int n, m;
    int a, b;
    Node node;
    vector<Node> nodes;

    while (cin >> n >> m) {
        nodes.clear();
        nodes.reserve(n);

        node.in = 0;
        node.mark = false;
        for (int i = 0; i != n; ++i) {
            nodes.push_back(node);
        }

        for (int i = 0; i != m; ++i) {
            cin >> a >> b;
            nodes[a].out.push_back(b);
            nodes[b].in++;
        }
        if (check_topo(nodes))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}
