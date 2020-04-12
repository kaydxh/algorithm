//
// Created by kayxhding on 2020-04-12 17:50:39
//
/*
 You are given two non-empty linked lists representing two non-negative
integers. The digits are stored in reverse order and each of their nodes contain
a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the
number 0 itself.

Example:

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <algorithm>
#include <iostream>
using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
 public:
  /*
      1. 新建一个值为-1的ListNode* result（亚节点），result->next 记为头指针
      2. 两个链表逐一 相加，和为2个链表的val相加， 再加上进位carry
      3. 将相加之和保存到新建节点中，直到两个链表都为空。
      4. 如果一个链表为空另一个不为空，可以令为空的链表的val为0，一直处理
      5. 不能使用先把2个链表全部相加，再把结果存入result
  ListNode，因为如果原链表数据比较大，会导致相加后，超出整数范围
    复杂度分析:
  时间复杂度：O(\max(m, n))O(max(m,n))，假设 mm 和 nn 分别表示 l1l1 和 l2l2
  的长度，上面的算法最多重复 \max(m, n)max(m,n) 次。
  空间复杂度：O(\max(m, n))O(max(m,n))， 新列表的长度最多为 \max(m,n) +
  1max(m,n)+1。
  */
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* result = new ListNode(-1);
    if (nullptr == result) {
      return nullptr;
    }
    ListNode* cur = result;
    int l1_val = 0;
    int l2_val = 0;
    int carry = 0;
    while (l1 || l2) {
      if (nullptr == l1) {
        l1_val = 0;

      } else {
        l1_val = l1->val;
      }

      if (nullptr == l2) {
        l2_val = 0;

      } else {
        l2_val = l2->val;
      }
      int sum = l1_val + l2_val + carry;
      carry = sum / 10;
      cur->next = new ListNode(sum % 10);
      if (nullptr == cur->next) {
        return nullptr;
      }
      cur = cur->next;
      if (l1) {
        l1 = l1->next;
      }
      if (l2) {
        l2 = l2->next;
      }
    }
    if (carry > 0) {
      cur->next = new ListNode(carry);
      if (nullptr == cur->next) {
        return nullptr;
      }
    }
    return result->next;
  }
#if 0
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    if (nullptr == l1 || nullptr == l2) {
      return nullptr;
    }

    ListNode* result = nullptr;
    int l1_val = 0;
    int l2_val = 0;
    int i = 0;
    for (auto it = l1; it != nullptr; it = it->next) {
      l1_val += it->val * pow(10, i);
      ++i;
    }
    i = 0;
    for (auto it = l2; it != nullptr; it = it->next) {
      l2_val += it->val * pow(10, i);
      ++i;
    }

    int sum = l1_val + l2_val;
    ListNode* p = result;
    for (auto val = 0; sum > 0; sum /= 10) {
      val = sum % 10;

      ListNode* q = getNewNode(val);
      if (result == nullptr) {
        p = q;
        result = p;
      } else {
        p->next = q;
        p = p->next;
      }
    }

    return result;
  }

 private:
  ListNode* getNewNode(int value) {
    ListNode* l = new ListNode(value);
    if (nullptr == l) {
      return nullptr;
    }

    return l;
  }
#endif
};

int main() {
  ListNode* p1 = new ListNode(2);
  ListNode* h1 = p1;
  p1->next = new ListNode(4);
  p1 = p1->next;
  p1->next = new ListNode(3);
  p1 = p1->next;

  ListNode* p2 = new ListNode(5);
  ListNode* h2 = p2;
  p2->next = new ListNode(6);
  p2 = p2->next;
  p2->next = new ListNode(4);
  p2 = p2->next;

  Solution sol;
  auto result = sol.addTwoNumbers(h1, h2);
  for (auto it = result; it != nullptr; it = it->next) {
    cout << it->val << " ";
  }
  return 0;
}
