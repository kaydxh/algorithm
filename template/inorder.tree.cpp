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
 * 中序遍历: 左中右
 * 递归:
 * 1. 递归方法一般定义一个帮助函数处理
 * 2. 按照左中右原则，先递归处理左子树,保存中间节点(左子树最深处的中间
 * 节点)，在递归处理右子树
 * 时间复杂度：O(n)
 * 空间复杂度：O(n)
 */
vector<int> inorderTraversal(TreeNode* root) {
    vector<int> result;
    inorder(root, result);
    return result;
}

void inorder(TreeNode* node, vector<int>& result) {
    if (nullptr == node) {
        return;
    }

    inorder(node->left, result);
    result.push_back(node->val);
    inorder(node->right, result);
}

/*
 * 中序遍历: 左中右
 * 迭代：
 * 1. 按照定义，左->中->右，(实际可以看作就左右节点,
 * 遍历时，中间节点也是左节点), 遍历时先遍历左子树直到结束,
 * 然后弹出节点，保存最左结点数值，然后遍历该节点的右子树
 * 先进后出原则，因此使用stack
 * 2 初始化初始
 * 3 遍历左子树到最后
 * 4 弹出最新的节点，保存节点值，得到右节点, 迭代遍历
 */
vector<int> inorderTraversal2(TreeNode* root) {
    vector<int> result;
    stack<TreeNode*> nodes_stack;
    TreeNode* node = root;

    while (node != nullptr || !nodes_stack.empty()) {
        while (node != nullptr) {
            nodes_stack.push(node);
            node = node->left;
        }

        node = nodes_stack.top();
        nodes_stack.pop();
        result.push_back(node->val);
        node = node->right;
    }

    return result;
}
