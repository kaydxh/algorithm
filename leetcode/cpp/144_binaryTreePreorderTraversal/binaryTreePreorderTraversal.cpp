//
// Created by kayxhding on 2020-06-28 23:53:23
//
/*
   Given a binary tree, return the preorder traversal of its nodes' values.

Example:

Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [1,2,3]
Follow up: Recursive solution is trivial, could you do it iteratively?
 */

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
 public:
  vector<int> preorderTraversal(TreeNode* root) {
    vector<int> result;
    stack<TreeNode*> nodes_stack;
    TreeNode* node = root;
    while (node != nullptr || !nodes_stack.empty()) {
      if (node != nullptr) {
        result.push_back(node->val);
        nodes_stack.push(node);
        node = node->left;
      }

      node = nodes_stack.top();
      nodes_stack.pop();
      node = node->right;
    }

    return result;
  }
};

int main() {
  TreeNode* p1 = new TreeNode(1);
  TreeNode* p2 = new TreeNode(2);
  TreeNode* p3 = new TreeNode(3);

  p1->right = p2;
  p2->left = p3;

  Solution sol;
  auto result = sol.preorderTraversal(p1);
  for (auto& e : result) {
    cout << e << " ";
  }
  cout << endl;
}
