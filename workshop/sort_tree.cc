#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Node {
  Node *left, *right;
  char c;
};

void preOrder(Node *T, vector<char> &buf) {
  buf.push_back(T->c);
  if (T->left) preOrder(T->left, buf);
  if (T->right) preOrder(T->right, buf);
}

void inOrder(Node *T, vector<char> &buf) {
  if (T->left) inOrder(T->left, buf);
  buf.push_back(T->c);
  if (T->right) inOrder(T->right, buf);
}

void postOrder(Node *T, vector<char> &buf) {
  if (T->left) postOrder(T->left, buf);
  if (T->right) postOrder(T->right, buf);
  buf.push_back(T->c);
}

void insert(Node *&T, char z) {
  Node *x = T;
  Node *y = nullptr;
  while (x) {
    y = x;
    if (z == x->c) return;
    if (z < x->c)
      x = x->left;
    else if (z > x->c)
      x = x->right;
  }
  if (!y) {
    T = new Node;
    T->c = z;
  } else if (z < y->c) {
    Node *n = new Node;
    n->c = z;
    y->left = n;
  } else {
    Node *n = new Node;
    n->c = z;
    y->right = n;
  }
}

int main(int argc, const char *argv[]) {
  int n;
  char c;
  vector<char> pre;
  vector<char> in;

  while (cin >> n) {
    Node *T = nullptr;
    for (int i = 0; i != n; ++i) {
      cin >> c;
      insert(T, c);
    }

    in.clear();
    inOrder(T, in);
    for (auto i : in) cout << i;
    cout << endl;
  }
  return 0;
}