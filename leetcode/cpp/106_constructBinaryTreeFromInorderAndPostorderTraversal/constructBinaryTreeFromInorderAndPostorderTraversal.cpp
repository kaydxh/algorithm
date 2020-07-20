//
// Created by kayxhding on 2020-07-20 22:50:37
//

/*
   Given inorder and postorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given

inorder = [9,3,15,20,7]
postorder = [9,15,7,20,3]
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
  TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    return buildTreeHelp(inorder, 0, inorder.size(), postorder, 0,
                         postorder.size());
  }

  TreeNode* buildTreeHelp(vector<int>& inorder, int i_start, int i_end,
                          vector<int>& postorder, int p_start, int p_end) {
    if (p_start == p_end) {
      return nullptr;
    }

    int root_val = postorder[p_end - 1];
    TreeNode* root = new TreeNode(root_val);

    int i_root_index = 0;
    for (int i = i_start; i < i_end; ++i) {
      if (inorder[i] == root_val) {
        i_root_index = i;
        break;
      }
    }

    int left_num = i_root_index - i_start;
    root->left = buildTreeHelp(inorder, i_start, i_root_index, postorder,
                               p_start, p_start + left_num);
    root->right = buildTreeHelp(inorder, i_root_index + 1, i_end, postorder,
                                p_start + left_num, p_end - 1);

    return root;
  }
};

int main() {
  vector<int> inorder = {3, 9, 15, 20, 7};
  vector<int> postorder = {9, 15, 7, 20, 3};
  Solution sol;
  auto root = sol.buildTree(inorder, postorder);
  cout << root->val << endl;
}
