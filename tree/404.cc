/*
 * @Description: Sum of Left Leaves
 * @Author: Chiale
 * @Date: 2022-03-29 10:55:28
 * @LastEditTime: 2022-03-29 17:53:26
 */

#include "tree.h"

using namespace std;

int sumOfLeftLeaves(TreeNode<int>* root) {
    if (root == nullptr) {
        return 0;
    }
    if (root->left == nullptr && root->right == nullptr) {
        return 0;
    }
    if (root->left != nullptr && root->left->left == nullptr &&
        root->left->right == nullptr) {
        return root->left->val + sumOfLeftLeaves(root->right);
    }
    return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
}

int main(int argc, const char* argv[]) {
    int n;
    string str;
    vector<string> treeTrace;
    while (cin >> n) {
        treeTrace.clear();
        treeTrace.reserve(n);
        for (auto i = 0; i != n; ++i) {
            cin >> str;
            treeTrace.push_back(str);
        }
        auto root = generateIntTree(treeTrace);
        cout << sumOfLeftLeaves(root) << endl;
    }
}