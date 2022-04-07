//
// Created by kayxhding on 2020-08-02 23:26:58
//

/*

Given a binary tree and a sum, find all root-to-leaf paths where each path's sum
equals the given sum.

Note: A leaf is a node with no children.

Example:

Given the below binary tree and sum = 22,

      5
     / \
    4   8
   /   / \
  11  13  4
 /  \    / \
7    2  5   1
Return:

[
   [5,4,11,2],
   [5,8,4,5]
]
 */

#include <iostream>
#include <vector>
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
     * 回溯
     * 时间复杂度：O(N^2)
     * 空间复杂度：O(N)
     */
    vector<vector<int>> pathSum(TreeNode *root, int sum) {
        vector<vector<int>> result;
        vector<int> path;
        if (root == nullptr) {
            return result;
        }

        backTrack(root, sum, path, result);
        return result;
    }

    void backTrack(TreeNode *node, int sum, vector<int> &path,
                   vector<vector<int>> &result) {
        if (node == nullptr) {
            return;
        }
        path.push_back(node->val);
        if (node->left == nullptr && node->right == nullptr) {
            if (sum == node->val) {
                // path.push_back(node->val);
                result.push_back(path);
                // path.pop_back();
            }

            // return;
        }

        if (node->left != nullptr) {
            // path.push_back(node->val);
            backTrack(node->left, sum - node->val, path, result);
            // path.pop_back();
        }

        if (node->right != nullptr) {
            // path.push_back(node->val);
            backTrack(node->right, sum - node->val, path, result);
            // path.pop_back();
        }
        // path.pop_back();
    }
};

int main() {
    TreeNode *t1 = new TreeNode(5);
    TreeNode *t2 = new TreeNode(4);
    TreeNode *t3 = new TreeNode(8);
    TreeNode *t4 = new TreeNode(11);
    TreeNode *t5 = new TreeNode(13);
    TreeNode *t6 = new TreeNode(4);
    TreeNode *t7 = new TreeNode(7);
    TreeNode *t8 = new TreeNode(2);
    TreeNode *t9 = new TreeNode(5);
    TreeNode *t10 = new TreeNode(1);

    t1->left = t2;
    t1->right = t3;
    t2->left = t4;
    t3->left = t5;
    t3->right = t6;
    t4->left = t7;
    t4->right = t8;
    t6->left = t9;
    t6->right = t10;

    Solution sol;
    auto result = sol.pathSum(t1, 22);

    for (auto i = 0; i < result.size(); ++i) {
        for (auto j = 0; j < result[i].size(); ++j) {
            cout << result[i][j] << " ";
        }

        cout << endl;
    }
}
