//
// Created by kayxhding on 2020-08-06 23:38:15
//

/*
   You are given a perfect binary tree where all leaves are on the same level,
and every parent has two children. The binary tree has the following definition:

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
Populate each next pointer to point to its next right node. If there is no next
right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

 

Follow up:

You may only use constant extra space.
Recursive approach is fine, you may assume implicit stack space does not count
as extra space for this problem.  

Example 1:



Input: root = [1,2,3,4,5,6,7]
Output: [1,#,2,3,#,4,5,6,7,#]
Explanation: Given the above perfect binary tree (Figure A), your function
should populate each next pointer to point to its next right node, just like in
Figure B. The serialized output is in level order as connected by the next
pointers, with '#' signifying the end of each level.  

Constraints:

The number of nodes in the given tree is less than 4096.
-1000 <= node.val <= 1000
*/

#include <iostream>
#include <queue>
using namespace std;

class Node {
 public:
  int val;
  Node* left;
  Node* right;
  Node* next;

  Node() : val(0), left(NULL), right(NULL), next(NULL) {}

  Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

  Node(int _val, Node* _left, Node* _right, Node* _next)
      : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
 public:
#if 1
  //树的层次遍历基于广度优先搜索
  //时间复杂度：O(N)
  //空间复杂度：O(N)
  Node* connect(Node* root) {
    if (nullptr == root) {
      return nullptr;
    }
    std::queue<Node*> nodes;
    nodes.push(root);

    while(!nodes.empty()) {
        int n = nodes.size();
        Node* last = nullptr;
        for (int i = 0; i < n; ++i) {
            Node *node = nodes.front();
            nodes.pop();
            if (node->left) {
                nodes.push(node->left);
            }
            if (node->right) {
                nodes.push(node->right);
            }
            if (last) {
                last->next= node;
            }
            last = node;
        }
    }

    return root;
  }
#endif

#if 0
  /*
  迭代：
  1. 使用pre保存每层的开始节点， cur为当前遍历的节点
  2. 遍历的时候，判断当前节点的下一层是否有节点，如果有，每层如下处理
  3. 当前cur->left->next = cur->right; if(cur->next) cur->right->next =
  cur->next->left; 4, 更新 cur = cur->next;
  5. 当前层遍历完成后，更新pre = pre->left

  时间复杂度：O(N)
  空间复杂度：O(1)
  */
  Node* connect(Node* root) {
    if (nullptr == root) {
      return nullptr;
    }

    Node* pre = root;
    Node* cur = nullptr;
    while (pre->left) {
      cur = pre;
      while (cur) {
        cur->left->next = cur->right;
        if (cur->next) {
          cur->right->next = cur->next->left;
        }

        cur = cur->next;
      }

      pre = pre->left;
    }

    return root;
  }
#endif
};

int main() {
  Node* t1 = new Node(1);
  Node* t2 = new Node(2);
  Node* t3 = new Node(3);
  Node* t4 = new Node(4);
  Node* t5 = new Node(5);
  Node* t6 = new Node(6);
  Node* t7 = new Node(7);

  t1->left = t2;
  t1->right = t3;
  t2->left = t4;
  t2->right = t5;
  t3->left = t6;
  t3->right = t7;

  Solution sol;
  auto result = sol.connect(t1);
  auto pre = result;
  while (pre) {
    auto cur = pre;
    while (cur) {
      cout << cur->val << " ";
      cur = cur->next;
    }

    cout << "#" << endl;
    pre = pre->left;
  }
}
