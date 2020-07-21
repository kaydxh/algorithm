//
// Created by kayxhding on 2020-07-21 23:36:22
//

/*
Given a binary tree, return the bottom-up level order traversal of its nodes'
values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
]

*/

#include <iostream>
#include <queue>
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
  vector<vector<int>> levelOrderBottom(TreeNode* root) {
    vector<vector<int>> result;
    TreeNode* node = root;
    queue<TreeNode*> nodes_queue;
    if (node != nullptr) {
      nodes_queue.push(node);
    }
    while (!nodes_queue.empty()) {
      int level_nums = nodes_queue.size();
      vector<int> level_elems;
      for (int i = 0; i < level_nums; ++i) {
        node = nodes_queue.front();
        nodes_queue.pop();
        if (node->left) {
          nodes_queue.push(node->left);
        }
        if (node->right) {
          nodes_queue.push(node->right);
        }
        level_elems.push_back(node->val);
      }

      if (level_elems.size() > 0) {
        result.insert(result.begin(), level_elems);
      }
    }

    return result;
  }
};

int main() {
  TreeNode* p1 = new TreeNode(3);
  TreeNode* p2 = new TreeNode(9);
  TreeNode* p3 = new TreeNode(20);
  TreeNode* p4 = new TreeNode(15);
  TreeNode* p5 = new TreeNode(7);
  p1->left = p2;
  p1->right = p3;
  p2->left = p4;
  p2->right = p5;

  Solution sol;
  auto result = sol.levelOrderBottom(p1);
  for (auto level_elems : result) {
    for (auto elem : level_elems) {
      std::cout << elem << " ";
    }
    cout << endl;
  }
}
