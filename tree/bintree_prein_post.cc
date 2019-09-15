/*
 * @Description: generate the post order from pre & in order
 * @Author: Chiale
 * @Date: 2019-09-04 16:04:07
 * @LastEditTime: 2019-09-15 09:15:57
 */

#include <iostream>
#include <string>

using namespace std;

void BinaryTreeFromOrderings(string pre_order, string in_order, int p_begin,
                             int p_end, int i_begin, int i_end) {
  if (p_begin >= p_end || i_begin >= i_end) {
    return;
  }

  char c = pre_order[p_begin];
  // auto root = find(in_order.begin() + i_begin, in_order.begin() + i_end, c);
  // int rootIndex = root - in_order.begin();
  int rootIndex = i_begin;
  for (; rootIndex != i_end; rootIndex++) {
    if (in_order[rootIndex] == c) break;
  }
  // Left
  int left_length = rootIndex - i_begin;
  int right_length = i_end - rootIndex - 1;
  // cout << ":" << pre_order << "[" << p_begin << "," << p_end << ")";
  // cout << ":" << in_order << "[" << i_begin << "," << i_end << ")";
  // cout << "left:" << left_length << "right:" << right_length << endl;

  if (left_length > 0)
    BinaryTreeFromOrderings(pre_order, in_order, p_begin + 1,
                            p_begin + 1 + left_length, i_begin,
                            i_begin + left_length);
  // Right
  if (right_length > 0)
    BinaryTreeFromOrderings(pre_order, in_order, p_end - right_length, p_end,
                            i_end - right_length, i_end);
  cout << c;
  return;
}

int main(int argc, char* argv[]) {
  string pre_order, in_order;
  while (cin >> pre_order) {
    cin >> in_order;
    BinaryTreeFromOrderings(pre_order, in_order, 0, pre_order.size(), 0,
                            in_order.size());
    cout << endl;
  }
  return 0;
}