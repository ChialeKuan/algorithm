/*
 * @Description:
 * @Author: Chiale
 * @Date: 2022-03-29 11:22:46
 * @LastEditTime: 2022-03-29 16:37:29
 */

#include <iostream>
#include <queue>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::queue;
using std::stoi;
using std::string;
using std::vector;

template <typename T>
struct TreeNode {
    T val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(T x) : val(x), left(NULL), right(NULL) {}
};

TreeNode<char>* generateTreePreIn(string pre_order, string in_order, int p_begin,
                             int p_end, int i_begin, int i_end);

void printTree(TreeNode<char>* root);

TreeNode<char>* generateCharTree(vector<string>& treeTrace);
TreeNode<int>* generateIntTree(vector<string>& treeTrace);
