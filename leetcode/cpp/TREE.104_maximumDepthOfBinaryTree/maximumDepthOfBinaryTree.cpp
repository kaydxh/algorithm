//
// Created by kayxhding on 2020-07-03 19:34:11
//

/*
   Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root
node down to the farthest leaf node.

Note: A leaf is a node with no children.

Example:

Given binary tree [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
return its depth = 3.

*/

#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
   public:
    /*
    利用层次遍历，获取层数，即为高
    复杂度：
    时间复杂度：O(n)
    空间复杂度：O(n)
  */
    int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int result = 0;
        queue<TreeNode*> nodes_queue;
        nodes_queue.push(root);

        while (!nodes_queue.empty()) {
            int elemNum = nodes_queue.size();
            for (int i = 0; i < elemNum; ++i) {
                TreeNode* node = nodes_queue.front();
                nodes_queue.pop();
                if (node->left != nullptr) {
                    nodes_queue.push(node->left);
                }

                if (node->right != nullptr) {
                    nodes_queue.push(node->right);
                }
            }
            ++result;
        }

        return result;
    }

    /*
    利用深度优选遍历，利用递归
    1. 根节点为nullptr， 即深度为0，退出, 递归退出出口
    2. 否则深度we 1 + 最子树和右子树深度的最大值,递归求解
    复杂度：
    时间复杂度：O(n)
    空间复杂度：O(n)
  */
    int maxDepth2(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        return 1 + max(maxDepth2(root->left), maxDepth2(root->right));
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
    cout << sol.maxDepth2(p1) << endl;
}
