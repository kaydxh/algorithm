//
// Created by kayxhding on 2020-07-13 22:38:44
//

/*
   Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's
key. The right subtree of a node contains only nodes with keys greater than the
node's key. Both the left and right subtrees must also be binary search trees.  

Example 1:

    2
   / \
  1   3

Input: [2,1,3]
Output: true
Example 2:

    5
   / \
  1   4
     / \
    3   6

Input: [5,1,4,null,null,3,6]
Output: false
Explanation: The root node's value is 5 but its right child's value is 4.
*/

#include <iostream>
#include <stack>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
 public:
  /*
 方法一：递归
 1. 判断左子树中最大的value 是否 < 根节点
 2. 判断右子树中最小的value 是否 > 根节点
 3. 递归判断

 方法二： 中序遍历
 1. 左->中->右，其实就是左->右
 2. 判断相连的node，val是否满足关系

 复杂度：
 1。 时间复杂度O(n)
 2.  空间复杂度O(n)
*/
  bool isValidBST(TreeNode *root) {
    stack<TreeNode *> nodes_stack;
    TreeNode *node = root;
    TreeNode *pre_node = nullptr;
    while (node != nullptr || !nodes_stack.empty()) {
      while (node != nullptr) {
        nodes_stack.push(node);
        node = node->left;
      }

      node = nodes_stack.top();
      nodes_stack.pop();
      if (pre_node != nullptr && pre_node->val >= node->val) {
        return false;
      }
      pre_node = node;
      node = node->right;
    }

    return true;
  }
};

int main() {
  TreeNode *p1 = new TreeNode(2);
  TreeNode *p2 = new TreeNode(1);
  TreeNode *p3 = new TreeNode(3);
  p1->left = p2;
  p1->right = p3;

  Solution sol;
  auto result = sol.isValidBST(p1);
  std::cout << result << std::endl;
}
