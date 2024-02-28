//
// Created by kayxhding on 2020-07-05 22:25:28
//

/*
   Given a binary tree, check whether it is a mirror of itself (ie, symmetric
around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
 

But the following [1,2,2,null,3,null,3] is not:

    1
   / \
  2   2
   \   \
   3    3

 时间复杂度是 O(n)，空间复杂度是 O(n)
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
     * 递归
     * 判断树的对称、相同时，需要用到左右子树比较时，一般定义一个帮助函
     * 数，参数为两个树的根节点
     */
    bool isSymmetric(TreeNode *root) {
        if (root == nullptr) {
            return true;
        }

        return isSymmetricTree(root->left, root->right);
    }

    bool isSymmetricTree(TreeNode *t1, TreeNode *t2) {
        if (t1 == nullptr && t2 == nullptr) {
            return true;
        }

        if (t1 == nullptr || t2 == nullptr) {
            return false;
        }

        if (t1->val != t2->val) {
            return false;
        }

        //对称性，因此用t1的左子树和t2的右子树比较， t1的右子树和t2的左
        //子树比较
        return isSymmetricTree(t1->left, t2->right) &&
               isSymmetricTree(t1->right, t2->left);
    }

    /*
     * 迭代
     * 使用层次遍历, 比较2个节点的值是否相同
     * 因此是对称比较， 如队时，2颗树的节点相反入队
     *
     */

    bool isSymmetric2(TreeNode *root) {
        if (root == nullptr) {
            return true;
        }
        return isSymmetricHelp(root->left, root->right);
    }

    bool isSymmetricHelp(TreeNode *p, TreeNode *q) {
        queue<TreeNode *> nodesQue;
        nodesQue.push(p);
        nodesQue.push(q);
        while (!nodesQue.empty()) {
            TreeNode *pNode = nodesQue.front();
            nodesQue.pop();
            TreeNode *qNode = nodesQue.front();
            nodesQue.pop();
            if (!pNode && !qNode) {
                continue;
            }
            if (!pNode && qNode) {
                return false;
            }
            if (!qNode && pNode) {
                return false;
            }

            if (pNode->val != qNode->val) {
                return false;
            }

            nodesQue.push(pNode->left);
            nodesQue.push(qNode->right);

            nodesQue.push(pNode->right);
            nodesQue.push(qNode->left);
        }

        return true;
    }
};

int main() {
    TreeNode *p1 = new TreeNode(1);
    TreeNode *p2 = new TreeNode(2);
    TreeNode *p3 = new TreeNode(2);
    TreeNode *p4 = new TreeNode(3);
    TreeNode *p5 = new TreeNode(4);
    TreeNode *p6 = new TreeNode(4);
    TreeNode *p7 = new TreeNode(3);

    p1->left = p2;
    p1->right = p3;
    p2->left = p4;
    p2->right = p5;
    p3->left = p6;
    p3->right = p7;

    Solution sol;
    auto result = sol.isSymmetric2(p1);
    cout << result << endl;
}
