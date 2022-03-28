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
 * 后序遍历
 * 递归:
 * 1. 递归方法一般定义一个帮助函数处理
 * 2. 按照左右中原则，在递归处理左、右子树, 最后保存中间节点, 即先输出左
 * 子树最深处的左节点、右节点、中间结点，原树的根节点最后输出
 * 时间复杂度：O(n)
 * 空间复杂度：O(n)
 */

vector<int> postorderTraversal(TreeNode* root) {
    vector<int> result;
    postorder(root, result);
    return result;
}

void postorder(TreeNode* root, vector<int>& result) {
    if (root == nullptr) {
        return;
    }
    preorder(root->left, result);
    preorder(root->right, result);
    result.push_back(root->val);
}

/*
  迭代
  1.
  对于后序遍历，当我们到达根节点的时候并不能立刻把根节点弹出，因为遍历完右子树，我们还需要将这个根节点加入到
  result中，所以我们就需要判断是从左子树到的根节点，还是右子树到的根节点
  2.
  如果是从左子树到的根节点，此时应该转到右子树。如果是从右子树到的根节点，那么就可以把当前节点弹出，并且加入到
  result中。
  3. 当然，如果是从左子树到的根节点，此时如果根节点的右子树为 null，
  此时也可以把当前节点弹出，并且加入到 list 中
  4. 如果当前节点的右节点和上一次遍历的节点相同，那就表明当前是从右节点过来的了
  复杂度：
  时间复杂度：O(n)
  空间复杂度：O(n)
  */
vector<int> postorderTraversal(TreeNode* root) {
    vector<int> result;
    stack<TreeNode*> nodes_stack;
    TreeNode* node = root;
    TreeNode* last_node = nullptr;
    while (node != nullptr || !nodes_stack.empty()) {
        while (node != nullptr) {
            nodes_stack.push(node);
            node = node->left;
        }

        // tmp_node为最左子树，最深的结点，可以看作当前最深入的中间节点
        TreeNode* tmp_node = nodes_stack.top();
        //右子树为空或者时从右子树来到这里
        if (tmp_node->right == nullptr || last_node == tmp_node->right) {
            result.push_back(tmp_node->val);
            nodes_stack.pop();
            last_node = tmp_node;

            //从左子树来到这里，就转向右子树
        } else {
            node = tmp_node->right;
        }
    }

    return result;
}
