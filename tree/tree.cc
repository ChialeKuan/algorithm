/*
 * @Description: generate a tree from pre & in order
 * @Author: Chiale
 * @Date: 2022-03-29 11:01:05
 * @LastEditTime: 2022-03-29 16:37:27
 */

#include "tree.h"

// char
TreeNode<char>* generateCharTree(vector<string>& treeTrace) {
    if (treeTrace.empty() or treeTrace[0] == "null") {
        return nullptr;
    }
    auto root = new TreeNode<char>(treeTrace[0]);
    queue<TreeNode<char>*> q;
    q.push(root);
    int i = 1;
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        if (i < treeTrace.size() && treeTrace[i] != "null") {
            cur->left = new TreeNode<char>(treeTrace[i]);
            q.push(cur->left);
        }
        i++;
        if (i < treeTrace.size() && treeTrace[i] != "null") {
            cur->right = new TreeNode<char>(treeTrace[i]);
            q.push(cur->right);
        }
        i++;
    }
}

TreeNode<char>* generateTreePreIn(string pre_order, string in_order,
                                  int p_begin, int p_end, int i_begin,
                                  int i_end) {
    if (p_begin >= p_end || i_begin >= i_end) {
        return NULL;
    }
    char c = pre_order[p_begin];
    int rootIndex = i_begin;
    for (; rootIndex != i_end; rootIndex++) {
        if (in_order[rootIndex] == c) {
            break;
        }
    }
    auto left_length = rootIndex - i_begin;
    auto right_length = i_end - rootIndex - 1;
    auto root = new TreeNode(c);
    root->left = generateTreePreIn(pre_order, in_order, p_begin + 1,
                                   p_begin + 1 + left_length, i_begin,
                                   i_begin + left_length);
    root->right = generateTreePreIn(pre_order, in_order, p_end - right_length,
                                    p_end, i_end - right_length, i_end);
    return root;
}

void printTree(TreeNode<char>* root) {
    if (root == NULL) {
        return;
    }
    printTree(root->left);
    printTree(root->right);
    cout << root->val;
}

// int
TreeNode<int>* generateIntTree(vector<string>& treeTrace) {
    if (treeTrace.empty() or treeTrace[0] == "null") {
        return nullptr;
    }
    auto root = new TreeNode<int>(stoi(treeTrace[0]));
    queue<TreeNode<int>*> q;
    q.push(root);
    int i = 1;
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        if (i < treeTrace.size()) {
            if (treeTrace[i] != "null") {
                auto left = new TreeNode<int>(stoi(treeTrace[i]));
                cur->left = left;
                q.push(left);
            }
            i++;
            if (i < treeTrace.size()) {
                if (treeTrace[i] != "null") {
                    auto right = new TreeNode<int>(stoi(treeTrace[i]));
                    cur->right = right;
                    q.push(right);
                }
                i++;
            }
        }
    }
    return root;
}
