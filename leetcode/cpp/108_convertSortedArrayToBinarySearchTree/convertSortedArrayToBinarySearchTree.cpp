//
// Created by kayxhding on 2020-07-22 23:19:51
//

/*
   Given an array where elements are sorted in ascending order, convert it to a
height balanced BST.

For this problem, a height-balanced binary tree is defined as a binary tree in
which the depth of the two subtrees of every node never differ by more than 1.

Example:

Given the sorted array: [-10,-3,0,5,9],

One possible answer is: [0,-3,9,-10,null,5], which represents the following
height balanced BST:

      0
     / \
   -3   9
   /   /
 -10  5

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
  TreeNode* sortedArrayToBST(vector<int>& nums) {
    return sortedArrayToBSTHelp(nums, 0, nums.size());
  }

  TreeNode* sortedArrayToBSTHelp(vector<int>& nums, int start, int end) {
    if (start == end) {
      return nullptr;
    }

    int mid = start + (end - start) / 2;
    int root_val = nums[mid];
    TreeNode* root = new TreeNode(root_val);
    root->left = sortedArrayToBSTHelp(nums, start, mid);
    root->right = sortedArrayToBSTHelp(nums, mid + 1, end);

    return root;
  }
};

int main() {
  vector<int> nums = {-10, -3, 0, 5, 9};
  Solution sol;
  auto result = sol.sortedArrayToBST(nums);
  cout << result->val << endl;
}
