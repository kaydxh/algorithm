/*
 * 深度优选搜索之递归方法
 * 1. 定义DFS函数
 * 2. 定义一个DFSHelp
 * bool DFSHelp(TreeNode* root)
 * 分情况处理：
 * 1. 递归出口：root == nullptr
 * 2. root->left == nullptr
 * 3. root->right == nullpptr
 * 4. 递归左子树、右子树
 * 时间复杂度：O(n^2)
 * 空间复杂度：O(n),
 * 取决于递归调用的层数，递归调用的层数不超过n,n为二叉树的节点数
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

bool isBalanced(TreeNode *root) { return isBalancedHelp(root); }

//自顶向下
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

