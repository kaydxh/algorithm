//
// Created by kayxhding on 2020-08-11 08:48:10
//

/*
   Given a binary tree

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



Input: root = [1,2,3,4,5,null,7]
Output: [1,#,2,3,#,4,5,7,#]
Explanation: Given the above binary tree (Figure A), your function should
populate each next pointer to point to its next right node, just like in Figure
B. The serialized output is in level order as connected by the next pointers,
with '#' signifying the end of each level.  

Constraints:

The number of nodes in the given tree is less than 6000.
-100 <= node.val <= 100

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
  1. 定义一个dump指针，处理边界情况(cur->left == nullptr, cur->right ==
  nullptr， cur->next == nullptr)
      dump为一层的开始节点(dump本身并不属于该树，dump->next真正为第一个节点)，
  tail从一层的开始节点更新到最后一个节点，
  2. tail->next每次更新，也就是将node的next连接起来了
  3.  每层里更新cur节点，cur=cur->next
  4. 迭代到下一层时，更新cur=dump->next

  复杂度：
  时间复杂度：O(n)
  空间复杂度：O(1)
  */
  Node* connect(Node* root) {
    if (nullptr == root) {
      return nullptr;
    }

    Node* cur = root;
    while (cur != nullptr) {
      Node* dummy = new Node();
      Node* tail = dummy;

      while (cur) {
        if (cur->left != nullptr) {
          tail->next = cur->left;
          tail = tail->next;
        }

        if (cur->right != nullptr) {
          tail->next = cur->right;
          tail = tail->next;
        }

        cur = cur->next;
      }

      cur = dummy->next;
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
  Node* t7 = new Node(7);

  t1->left = t2;
  t1->right = t3;
  t2->left = t4;
  t2->right = t5;
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
