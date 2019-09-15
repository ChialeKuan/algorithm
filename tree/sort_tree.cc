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

void postOrder(Node *T) {
  if (T->left) postOrder(T->left);
  if (T->right) postOrder(T->right);
  cout << T->c;
}

Node *insert(Node *T, char x) {
  if (!T) {
    T = new Node;
    T->c = x;
    return T;
  }
  if (x == T->c) {
    return T;
  }
  if (x < T->c) {
    T->left = insert(T->left, x);
  } else if (x > T->c) {
    T->right = insert(T->right, x);
  }
  return T;
}

int main(int argc, const char *argv[]) {
  int n;
  string s;
  vector<char> pre_1;
  vector<char> in_1;
  vector<char> pre_2;
  vector<char> in_2;

  while (cin >> n) {
    s.clear();
    cin >> s;

    Node *T_1 = nullptr;
    for (int i = 0; i != s.size(); ++i) {
      T_1 = insert(T_1, s[i]);
    }

    pre_1.clear();
    in_1.clear();
    preOrder(T_1, pre_1);
    inOrder(T_1, in_1);

    for (int i = 0; i != n; ++i) {
      s.clear();
      cin >> s;

      Node *T_2 = nullptr;
      for (int i = 0; i != s.size(); ++i) {
        T_2 = insert(T_2, s[i]);
      }

      preOrder(T_2, pre_2);
      inOrder(T_2, in_2);
      if (pre_1 == pre_2 && in_1 == in_2)
        cout << "YES" << endl;
      else
        cout << "NO" << endl;
    }
  }
  return 0;
}