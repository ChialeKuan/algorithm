/*
 * @Description: 
 * @Author: Chiale
 * @Date: 2022-03-29 11:32:28
 * @LastEditTime: 2022-03-29 17:57:24
 */

#include "tree.h"

int main(int argc, char* argv[]) {
    string pre_order, in_order;
    while (cin >> pre_order) {
        cin >> in_order;
        auto root = generateTreePreIn(pre_order, in_order, 0, pre_order.size(),
                                      0, in_order.size());
        printTree(root);
        cout << endl;
        
    }
    return 0;
}