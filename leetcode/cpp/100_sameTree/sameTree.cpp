//
// Created by kayxhding on 2020-07-01 23:09:55
//

/*
   Given two binary trees, write a function to check if they are the same or
not.

Two binary trees are considered the same if they are structurally identical and
the nodes have the same value.

Example 1:

Input:     1         1
          / \       / \
         2   3     2   3

        [1,2,3],   [1,2,3]

Output: true
Example 2:

Input:     1         1
          /           \
         2             2

        [1,2],     [1,null,2]

Output: false
Example 3:

Input:     1         1
          / \       / \
         2   1     1   2

        [1,2,1],   [1,1,2]

Output: false

*/

#include <iostream>
using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
 public:
  bool isSameTree(TreeNode* p, TreeNode* q) {
    if (nullptr == p && nullptr == q) {
      return true;
    }

    if (nullptr == p || nullptr == q) {
      return false;
    }

    if (p->val != q->val) {
      return false;
    }

    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
  }
};

int main() {
  TreeNode* p1 = new TreeNode(1);
  TreeNode* p2 = new TreeNode(2);
  p1->left = p2;

  TreeNode* q1 = new TreeNode(1);
  TreeNode* q2 = new TreeNode(2);
  q1->right = q2;

  Solution sol;
  cout << sol.isSameTree(p1, q1) << endl;
}
