//
// Created by kayxhding on 2020-08-04 22:21:55
//

/*
   Given a binary tree, flatten it to a linked list in-place.

For example, given the following tree:

    1
   / \
  2   5
 / \   \
3   4   6
The flattened tree should look like:

1
 \
  2
   \
    3
     \
      4
       \
        5
         \
          6

*/

#include <iostream>
#include <stack>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
 public:
  void flatten(TreeNode *root) {
    if (nullptr == root) {
      return;
    }

    TreeNode *node = root;
    stack<TreeNode *> nodes_stack;
    if (node != nullptr) {
      nodes_stack.push(node);
    }

    TreeNode *pre_node = nullptr;
    while (!nodes_stack.empty()) {
      node = nodes_stack.top();
      nodes_stack.pop();
      if (pre_node != nullptr) {
        pre_node->right = node;
        pre_node->left = nullptr;
      }

      if (node->right != nullptr) {
        nodes_stack.push(node->right);
      }

      if (node->left != nullptr) {
        nodes_stack.push(node->left);
      }

      pre_node = node;
    }
  }
};

int main() {
  TreeNode *t1 = new TreeNode(1);
  TreeNode *t2 = new TreeNode(2);
  TreeNode *t3 = new TreeNode(5);
  TreeNode *t4 = new TreeNode(3);
  TreeNode *t5 = new TreeNode(4);
  TreeNode *t6 = new TreeNode(6);

  t1->left = t2;
  t1->right = t3;
  t2->left = t4;
  t2->right = t5;
  t3->right = t6;

  Solution sol;
  sol.flatten(t1);
  while (t1 != nullptr) {
    cout << t1->val << " ";
    t1 = t1->right;
  }
  cout << endl;
}
