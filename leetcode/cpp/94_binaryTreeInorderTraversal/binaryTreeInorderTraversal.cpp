//
// Created by kayxhding on 2020-06-28 08:09:40
//

/*
 Given a binary tree, return the inorder traversal of its nodes' values.

Example:

Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [1,3,2]
Follow up: Recursive solution is trivial, could you do it iteratively?

*/

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
  /*
方法一： 递归法
中序遍历： 左中右
方法二： 迭代
1. 利用栈，去模拟递归。
2.
递归压栈的过程，就是保存现场，就是保存当前的变量，而解法一中当前有用的变量就是
node，所以我们用栈把每次的 node 保存起来即可

复杂度：
1. 时间复杂度：O（n）
2. 空间复杂度：O（h），压栈消耗，h 是二叉树的高度。
*/
 public:
#if 0
  vector<int> inorderTraversal(TreeNode *root) {
    vector<int> result;
    inorder(root, result);
    return result;
  }

  void inorder(TreeNode *node, vector<int> &result) {
    if (nullptr == node) {
      return;
    }

    inorder(node->left, result);
    result.push_back(node->val);
    inorder(node->right, result);
  }

#endif
  vector<int> inorderTraversal(TreeNode *root) {
    vector<int> result;
    stack<TreeNode *> nodes_stack;
    TreeNode *node = root;

    while (node != nullptr || !nodes_stack.empty()) {
      while (node != nullptr) {
        nodes_stack.push(node);
        node = node->left;
      }

      node = nodes_stack.top();
      nodes_stack.pop();
      result.push_back(node->val);
      node = node->right;
    }

    return result;
  }
};

int main() {
  TreeNode *p1 = new TreeNode(1);
  TreeNode *p2 = new TreeNode(2);
  TreeNode *p3 = new TreeNode(3);

  p1->right = p2;
  p2->left = p3;

  Solution sol;
  auto result = sol.inorderTraversal(p1);
  for (auto &e : result) {
    cout << e << " ";
  }
  cout << endl;
}
