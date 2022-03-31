//
// Created by kayxhding on 2020-07-31 21:37:43
//

/*

Given a binary tree and a sum, determine if the tree has a root-to-leaf path
such that adding up all the values along the path equals the given sum.

Note: A leaf is a node with no children.

Example:

Given the below binary tree and sum = 22,

      5
     / \
    4   8
   /   / \
  11  13  4
 /  \      \
7    2      1
return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
 */

#include <iostream>
#include <queue>
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
     * 深度优先搜索
     * 大问题可以转化为子问题,是否存在从当前节点到叶子节点的和为
     * sum-val
     * 步骤：
     * 1. 遍历左右子树，如果当前节点是叶子节点，那么sum == val,即满足条
     * 件
     * 时间复杂度：O(N)
     * 空间复杂度为 O(H), 最坏为O(N)
     */
    bool hasPathSum(TreeNode *root, int sum) {
        if (nullptr == root) {
            return false;
        }

        if (root->left == nullptr && root->right == nullptr) {
            if (sum == root->val) {
                return true;
            }

            return false;
        }

        bool has_left = hasPathSum(root->left, sum - root->val);
        bool has_right = hasPathSum(root->right, sum - root->val);

        return has_left || has_right;
    }

    /*
     * 广度优先搜索
     * 使用一个队列，保存根节点到当前节点的和
     * 1. 遍历过程中，每次将累加和push到队列中
     * 2. 当遍历到叶子节点时，队列中的tmpSum == sum, 即满足条件
     *
     * 时间复杂度：O(N)
     * 空间复杂度: O(N)
     */
    bool hasPathSum2(TreeNode *root, int sum) {
        if (nullptr == root) {
            return false;
        }

        queue<TreeNode *> nodesQue;
        nodesQue.push(root);
        queue<int> sumQue;
        sumQue.push(root->val);

        while (!nodesQue.empty()) {
            auto node = nodesQue.front();
            nodesQue.pop();
            int tmpSum = sumQue.front();
            sumQue.pop();

            if (node->left == nullptr && node->right == nullptr) {
                if (tmpSum == sum) {
                    return true;
                }
                continue;
            }

            if (node->left != nullptr) {
                nodesQue.push(node->left);
                sumQue.push(tmpSum + node->left->val);
            }
            if (node->right != nullptr) {
                nodesQue.push(node->right);
                sumQue.push(tmpSum + node->right->val);
            }
        }

        return false;
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
    TreeNode *t9 = new TreeNode(1);

    t1->left = t2;
    t1->right = t3;
    t2->left = t4;
    t3->left = t5;
    t3->right = t6;
    t4->left = t7;
    t4->right = t8;
    t6->right = t9;

    Solution sol;
    auto result = sol.hasPathSum2(t1, 22);
    std::cout << result << std::endl;
}
