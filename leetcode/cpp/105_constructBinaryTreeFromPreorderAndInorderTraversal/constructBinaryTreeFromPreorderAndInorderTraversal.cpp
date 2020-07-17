//
// Created by kayxhding on 2020-07-17 08:35:50
//

/*
   Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given

preorder = [3,9,20,15,7]
inorder = [9,3,15,20,7]
Return the following binary tree:

    3
   / \
  9  20
    /  \
   15   7

*/

#include <iostream>
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
  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    return buildTreeHelp(preorder, 0, preorder.size(), inorder, 0,
                         inorder.size());
  }

  TreeNode* buildTreeHelp(vector<int>& preorder, int p_start, int p_end,
                          vector<int>& inorder, int i_start, int i_end) {
    if (p_start == p_end) {
      return nullptr;
    }

    int root_val = preorder[p_start];
    TreeNode* root = new TreeNode(root_val);
    int i_root_index = 0;
    for (auto i = i_start; i < i_end; ++i) {
      if (inorder[i] == root_val) {
        i_root_index = i;
        break;
      }
    }

    int left_num = i_root_index - i_start;

    root->left = buildTreeHelp(preorder, p_start + 1, p_start + 1 + left_num,
                               inorder, i_start, i_root_index);
    root->right = buildTreeHelp(preorder, p_start + 1 + left_num, p_end,
                                inorder, i_root_index + 1, i_end);
    return root;
  }
};

int main() {
  vector<int> preorder = {3, 9, 20, 15, 7};
  vector<int> inorder = {9, 3, 15, 20, 7};
  Solution sol;
  auto root = sol.buildTree(preorder, inorder);
  cout << root->val << endl;
}
