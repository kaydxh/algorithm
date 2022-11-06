
/*
 * 树的遍历：
 * 1. 前序遍历
 * 2. 中序遍历
 * 3. 后续遍历
 * 4. 层次遍历
 */

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*
 * 前序遍历
 * 递归:
 * 1. 递归方法一般定义一个帮助函数处理
 * 2. 按照中左右原则，先保存中间节点，在递归处理左、右子树, 即根据点先处理保存
 * 时间复杂度：O(n)
 * 空间复杂度：O(n)
 */

vector<int> preorderTraversal(TreeNode* root) {
    vector<int> result;
    preorder(root, result);
    return result;
}

void preorder(TreeNode* root, vector<int>& result) {
    if (root == nullptr) {
        return;
    }
    result.push_back(root->val);
    preorder(root->left, result);
    preorder(root->right, result);
}

/*
 * 前序遍历: 中左右
 * 迭代：
 * 1. 按照定义，中->左->右，遍历时先保存中间结点数值，然后遍历左子树
 * 直到结束，再遍历最后保存节点的右子树，之后依次往更上层的右子树推.
 * 先进后出原则，因此使用stack
 * 2 初始化初始
 * 3 遍历左子树到最后
 * 4 弹出最新的节点，得到右节点, 保存结果
 */
vector<int> preorderTraversal2(TreeNode* root) {
    vector<int> result;
    stack<TreeNode*> nodes_stack;
    TreeNode* node = root;
    while (node != nullptr || !nodes_stack.empty()) {
        while (node != nullptr) {
            result.push_back(node->val);
            nodes_stack.push(node);
            node = node->left;
        }

        node = nodes_stack.top();
        nodes_stack.pop();
        node = node->right;
    }

    return result;
}

