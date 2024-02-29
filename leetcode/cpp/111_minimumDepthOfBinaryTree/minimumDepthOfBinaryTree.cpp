//
// Created by kayxhding on 2020-07-28 08:20:45
//

/*
   Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root
node down to the nearest leaf node.

Note: A leaf is a node with no children.

Example:

Given binary tree [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
return its minimum depth = 2.

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
  /*
     1. mindepth of binary tree must consider the case:
       left or right sub tree is empty, so the mindepth if not 0, but the depth
     of other sub tree which is not empty
     时间复杂度：O(N)
     空间复杂度：O(H)，其中 H 是树的高度。空间复杂度主要取决于递归时栈空间的开销，最坏情况下，树呈现链状，空间复杂度为 O(N)。平均情况下树的高度与节点数的对数正相关，空间复杂度为 O(logN)

     */
  int minDepth(TreeNode *root) {
    if (nullptr == root) {
      return 0;
    }

    return minDepthHelp(root);
  }

  int minDepthHelp(TreeNode *root) {
    if (nullptr == root->left && nullptr == root->right) {
      return 1;
    }

    if (root->left == nullptr) {
      return minDepthHelp(root->right) + 1;
    }

    if (root->right == nullptr) {
      return minDepthHelp(root->left) + 1;
    }

    return min(minDepthHelp(root->left), minDepthHelp(root->right)) + 1;
  }
};

int main() {
  TreeNode *p1 = new TreeNode(1);
  TreeNode *p2 = new TreeNode(2);
  TreeNode *p3 = new TreeNode(3);
  TreeNode *p4 = new TreeNode(4);
  TreeNode *p5 = new TreeNode(5);

  p1->left = p2;
  p1->right = p3;
  p2->left = p4;
  p3->right = p5;

  Solution sol;
  auto result = sol.minDepth(p1);

  cout << result << endl;
}
