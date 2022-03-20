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
#include <queue>
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
    /*
  一 递归, 回溯
  1. 二叉搜索树的性质，左子树 < 根 < 右子树
  2. 如果有1-n个节点，那么需要遍历1-n个几点，每个节点作为根节点的情况
  3. 如节点i为根节点，那么其左子树为[1，i-1]，其中i-1 >= 1, 右子树为[i+1, n]
  4. 之后对于左子树和右子树，递归处理

  */
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
            vector<TreeNode *> left_trees =
                generateTreesWithRange(start, i - 1);
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

    vector<int> levelTraverse(TreeNode *root) {
        vector<int> result;
        queue<TreeNode *> node_queue;
        TreeNode *node = root;
        if (node != nullptr) {
            node_queue.push(node);
        }

        while (!node_queue.empty()) {
            node = node_queue.front();
            if (node != nullptr) {
                result.push_back(node->val);
                if (node->left != nullptr) {
                    node_queue.push(node->left);
                }
                if (node->right != nullptr) {
                    node_queue.push(node->right);
                }
            }
            node_queue.pop();
        }

        return result;
    }
};

int main() {
    Solution sol;
    auto result = sol.generateTrees(3);
    for (auto e : result) {
        if (e != nullptr) {
            // cout << e->val;
            auto level_nodes = sol.levelTraverse(e);
            for (auto j : level_nodes) {
                cout << j;
            }
            cout << endl;
        } else {
            cout << "null";
        }
    }
    cout << endl;
}
