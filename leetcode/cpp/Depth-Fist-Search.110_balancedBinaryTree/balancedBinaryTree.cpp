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
        // return isBalancedHelp(root);
        return getTreeHeight2(root) >= 0;
    }

    /*
     * 递归： 自底向上递归，单层递归，避免节点的高度重复计算
     * 时间复杂度：O(n)
     * 空间复杂度：O(n)
     */
    int getTreeHeight2(TreeNode *root) {
        if (nullptr == root) {
            return 0;
        }
        int h1 = getTreeHeight2(root->left);
        int h2 = getTreeHeight2(root->right);
        // 非平衡时，高度返回-1
        if (h1 == -1 || h2 == -1 || abs(h1 - h2) > 1) {
            return -1;
        }
        return 1 + max(h1, h2);
    }

    /*
     * 递归： 自顶向下递归，双层递归，节点的高度有重复计算
     * 时间复杂度：O(n^2)
     * 空间复杂度：O(n)
     */
    bool isBalancedHelp(TreeNode *root) {
        if (root == nullptr) {
            return true;
        }

        int h1 = getTreeHeight(root->left);
        int h2 = getTreeHeight(root->right);
        if (abs(h1 - h2) > 1) {
            return false;
        }

        return isBalancedHelp(root->left) && isBalancedHelp(root->right);
    }

    int getTreeHeight(TreeNode *root) {
        if (nullptr == root) {
            return 0;
        }
        return 1 + max(getTreeHeight(root->left), getTreeHeight(root->right));
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
