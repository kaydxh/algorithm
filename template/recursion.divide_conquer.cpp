/*
 * 递归-divide and conquer 分治，将大问题转化为各个小问题，然后将小问题
 * 的解组合起来
 * 1 递归终止条件
 * 2 递归关系 =》 大问题转化为小问题
 */

#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool DivideAndConquerHelp(TreeNode* root) {
    /*
    //1. base case
       if (root == nullptr) {
          result  true;
        }

    //2. recursion relation
      //判断当前节点
      int h1 = getTreeHeight(root->left);
      int h2 = getTreeHeight(root->right);
      if (abs(h1 - h2) > 1) {
          return false;
      }
      // 拆成小问题
     bool r1 =  DivideAndConquerHelp(root->left)
     bool r2 = DivideAndConquerHelp(root->right);

    */

    // 3. combine
    // 结合小问题结果
    bool result = false;
    // result  =  r1 && r2;
    return result;
}

bool DivideAndConquer(TreeNode* root) { return DivideAndConquerHelp(root); }
