#include <string.h>
#include <fstream>
#include <iostream>
using namespace std;

/*二叉树的结构体*/
struct BTree {
  int val;
  struct BTree *left, *right;
};

/*二叉树的类，包含着操作二叉树的各种方法*/
class Tree {
 public:
  BTree *create_node(int level, string pos);
  void PreOrder(BTree *t);   //先序遍历
  void InOrder(BTree *t);    //中序遍历
  void PostOrder(BTree *t);  //后序遍历

  BTree *root;
};

/*用先序遍历的方法递归构造一课二叉树*/
BTree *Tree::create_node(int level, string pos) {
  int data;
  BTree *node = new BTree;
  cout << "please enter data:level " << level << " " << pos << endl;
  cin >> data;

  //若输入的数据为0，则把该结点的子结点置为空
  if (data == 0) {
    return NULL;
  }
  node->val = data;
  /*create_node（）的	参数用于在给二叉树赋值时表明
  现在赋值的是哪个结点*/
  node->left = create_node(level + 1, "left");
  node->right = create_node(level + 1, "right");
  return node;
}

void Tree::PreOrder(BTree *t) {
  if (t) {
    cout << t->val;
    PreOrder(t->left);
    PreOrder(t->right);
  }
}

void Tree::InOrder(BTree *t) {
  if (t) {
    InOrder(t->left);
    cout << t->val;
    InOrder(t->right);
  }
}

void Tree::PostOrder(BTree *t) {
  if (t) {
    PostOrder(t->left);
    PostOrder(t->right);
    cout << t->val;
  }
}

int main() {
  Tree tree;
  tree.root = tree.create_node(1, "root");

  cout << "Pre:\t";
  tree.PreOrder(tree.root);
  cout << endl;

  cout << "In:\t";
  tree.InOrder(tree.root);
  cout << endl;

  cout << "Post:\t";
  tree.PreOrder(tree.root);
  cout << endl;
  return 0;
}