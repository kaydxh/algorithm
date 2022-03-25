//
// Created by kayxhding on 2020-07-05 22:25:28
//

/*
   Given a binary tree, check whether it is a mirror of itself (ie, symmetric
around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
 

But the following [1,2,2,null,3,null,3] is not:

    1
   / \
  2   2
   \   \
   3    3

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
  bool isSymmetric(TreeNode *root) {
    if (root == nullptr) {
      return true;
    }

    return isSymmetricTree(root->left, root->right);
  }

  bool isSymmetricTree(TreeNode *t1, TreeNode *t2) {
    if (t1 == nullptr && t2 == nullptr) {
      return true;
    }

    if (t1 == nullptr || t2 == nullptr) {
      return false;
    }

    if (t1->val != t2->val) {
      return false;
    }

    return isSymmetricTree(t1->left, t2->right) &&
           isSymmetricTree(t1->right, t2->left);
  }
};

int main() {
  TreeNode *p1 = new TreeNode(1);
  TreeNode *p2 = new TreeNode(2);
  TreeNode *p3 = new TreeNode(2);
  TreeNode *p4 = new TreeNode(3);
  TreeNode *p5 = new TreeNode(4);
  TreeNode *p6 = new TreeNode(4);
  TreeNode *p7 = new TreeNode(3);

  p1->left = p2;
  p1->right = p3;
  p2->left = p4;
  p2->right = p5;
  p3->left = p6;
  p3->right = p7;

  Solution sol;
  auto result = sol.isSymmetric(p1);
  cout << result << endl;
}
