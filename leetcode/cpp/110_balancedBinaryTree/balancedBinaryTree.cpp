//
// Created by kayxhding on 2020-07-27 22:55:01
//

/*

Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as:

a binary tree in which the left and right subtrees of every node differ in
height by no more than 1.



Example 1:

Given the following tree [3,9,20,null,null,15,7]:

    3
   / \
  9  20
    /  \
   15   7
Return true.

Example 2:

Given the following tree [1,2,2,3,3,null,null,4,4]:

       1
      / \
     2   2
    / \
   3   3
  / \
 4   4
Return false
 */

#include <iostream>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
 public:
  bool isBalanced(TreeNode *root) {
    if (nullptr == root) {
      return true;
    }

    int left_height = getTreeHeight(root->left);
    int right_height = getTreeHeight(root->right);
    if (abs(left_height - right_height) > 1) {
      return false;
    }

    return isBalanced(root->left) && isBalanced(root->right);
  }

  int getTreeHeight(TreeNode *root) {
    if (nullptr == root) {
      return 0;
    }

    int left_height = getTreeHeight(root->left);
    int right_height = getTreeHeight(root->right);

    return left_height > right_height ? left_height + 1 : right_height + 1;
  }
};

int main() {
  TreeNode *p1 = new TreeNode(3);
  TreeNode *p2 = new TreeNode(9);
  TreeNode *p3 = new TreeNode(20);
  TreeNode *p4 = new TreeNode(15);
  TreeNode *p5 = new TreeNode(7);

  p1->left = p2;
  p1->right = p3;
  p3->left = p4;
  p3->right = p5;

  Solution sol;
  auto result = sol.isBalanced(p1);

  cout << result << endl;
}
