//
// Created by kayxhding on 2020-07-24 20:31:12
//

/*

Given a singly linked list where elements are sorted in ascending order, convert
it to a height balanced BST.

For this problem, a height-balanced binary tree is defined as a binary tree in
which the depth of the two subtrees of every node never differ by more than 1.

Example:

Given the sorted linked list: [-10,-3,0,5,9],

One possible answer is: [0,-3,9,-10,null,5], which represents the following
height balanced BST:

      0
     / \
   -3   9
   /   /
 -10  5
*/

#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
 public:
  /*
  method:  inorder traverse
  1. the order of inodrder traverse is just ascending, so we can use the feature
  to assign the node
     */
  TreeNode *sortedListToBST(ListNode *head) {
    ListNode *node = head;
    cur_node = node;
    int end = 0;
    while (node) {
      node = node->next;
      ++end;
    }

    return sortedListToBSTHelp(0, end);
  }

  TreeNode *sortedListToBSTHelp(int start, int end) {
    if (start == end) {
      return nullptr;
    }

    int mid = start + (end - start) / 2;
    TreeNode *left = sortedListToBSTHelp(start, mid);
    TreeNode *root = new TreeNode(cur_node->val);
    root->left = left;
    cur_node = cur_node->next;

    TreeNode *right = sortedListToBSTHelp(mid + 1, end);
    root->right = right;

    return root;
  }

 private:
  ListNode *cur_node = nullptr;
};

int main() {
  ListNode *p1 = new ListNode(-10);
  ListNode *p2 = new ListNode(-3);
  ListNode *p3 = new ListNode(0);
  ListNode *p4 = new ListNode(5);
  ListNode *p5 = new ListNode(9);

  p1->next = p2;
  p2->next = p3;
  p3->next = p4;
  p4->next = p5;

  Solution sol;
  auto result = sol.sortedListToBST(p1);

  cout << result->val << endl;
}
