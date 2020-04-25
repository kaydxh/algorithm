//
// Created by kayxhding on 2020-04-25 15:42:16
//
/*
Given a linked list, rotate the list to the right by k places, where k is
non-negative.

Example 1:

Input: 1->2->3->4->5->NULL, k = 2
Output: 4->5->1->2->3->NULL
Explanation:
rotate 1 steps to the right: 5->1->2->3->4->NULL
rotate 2 steps to the right: 4->5->1->2->3->NULL
Example 2:

Input: 0->1->2->NULL, k = 4
Output: 2->0->1->NULL
Explanation:
rotate 1 steps to the right: 2->0->1->NULL
rotate 2 steps to the right: 1->2->0->NULL
rotate 3 steps to the right: 0->1->2->NULL
rotate 4 steps to the right: 2->0->1->NULL
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <iostream>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
 public:
#if 0
  ListNode *rotateRight(ListNode *head, int k) {
    if (head == nullptr) {
      return nullptr;
    }
    if (k == 0) {
      return head;
    }
    int len = 0;
    ListNode *dummy = new ListNode(-1);
    dummy->next = head;
    ListNode *first_node = dummy;
    ListNode *second_node = dummy;
    while (first_node->next != nullptr) {
      first_node = first_node->next;
      ++len;
    }

    if (k >= len) {
      k = k % len;
    }
    if (0 == k) {
      return head;
    }
    for (auto i = 0; i < len - k; ++i) {
      second_node = second_node->next;
    }

    dummy->next = second_node->next;
    second_node->next = nullptr;
    first_node->next = head;

    return dummy->next;
  }
#endif
  ListNode *rotateRight(ListNode *head, int k) {
    if (head == nullptr) {
      return nullptr;
    }
    ListNode *p = head;
    int len = 1;
    while (p->next != nullptr) {
      p = p->next;
      ++len;
    }
    p->next = head;

    if (k >= len) {
      k = k % len;
    }

    p = head;
    for (auto i = 0; i < len - k - 1; ++i) {
      p = p->next;
    }

    head = p->next;
    p->next = nullptr;

    return head;
  }
};

int main() {
  ListNode *p1 = new ListNode(1);
  //  ListNode *p2 = new ListNode(2);
  //  ListNode *p3 = new ListNode(3);
  //  ListNode *p4 = new ListNode(4);
  //  ListNode *p5 = new ListNode(5);
  p1->next = nullptr;  // p2;
  //  p2->next = p3;
  //  p3->next = p4;
  //  p4->next = p5;
  // p5->next = nullptr;

  Solution sol;
  auto result = sol.rotateRight(p1, 1);
  while (result != nullptr && result->next != nullptr) {
    cout << result->val << "->";
    result = result->next;
  }

  if (result) {
    cout << result->val << endl;
  }
}
