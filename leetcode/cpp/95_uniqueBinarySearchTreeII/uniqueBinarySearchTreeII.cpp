//
// Created by kayxhding on 2020-07-07 22:46:13
//

/*
   Given an integer n, generate all structurally unique BST's (binary search
trees) that store values 1 ... n.

Example:

Input: 3
Output:
[
  [1,null,3,2],
  [3,2,null,1],
  [3,1,null,null,2],
  [2,1,3],
  [1,null,2,null,3]
]
Explanation:
The above output corresponds to the 5 unique BST's shown below:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
 

Constraints:

0 <= n <= 8

*/

#include <iostream>
#include <vector>
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
  vector<TreeNode *> generateTrees(int n) {
    if (n <= 0) {
      return {};
    }

    return generateTreesWithRange(1, n);
  }

  vector<TreeNode *> generateTreesWithRange(int start, int end) {
    vector<TreeNode *> all_trees;
    if (start > end) {
      all_trees.push_back(nullptr);
      return all_trees;
    }

    for (int i = start; i <= end; ++i) {
      vector<TreeNode *> left_trees = generateTreesWithRange(start, i - 1);
      vector<TreeNode *> right_trees = generateTreesWithRange(i + 1, end);

      for (auto left : left_trees) {
        for (auto right : right_trees) {
          TreeNode *node = new TreeNode(i);
          node->left = left;
          node->right = right;
          all_trees.push_back(node);
        }
      }
    }

    return all_trees;
  }
};

int main() {
  Solution sol;
  auto result = sol.generateTrees(3);
  for (auto e : result) {
    if (e != nullptr) {
      cout << e->val;
    } else {
      cout << "null";
    }
  }
  cout << endl;
}
