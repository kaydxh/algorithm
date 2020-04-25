//
// Created by kayxhding on 2020-04-25 11:59:49
//
/*
   Given a linked list, swap every two adjacent nodes and return its head.
You may not modify the values in the list's nodes, only nodes itself may be
changed.
Example:
Given 1->2->3->4, you should return the list as 2->1->4->3.
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
  ListNode* next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
 public:
  /*
  方法一递归：
  1. 如果没有节点或只有一个节点，就返回
  2. 使用2个指针，指向需要交换的node , first_node, second_node
  3. 递归second->next,
  并赋值为first_node->next，因为交换后原先第一个node的next将指向下一组交互的第一个节点
  4. 将second->next指向第一个元素
  5. 返回交换后的第一个节点指针，即second_node

  复杂度：
  时间复杂度：O(N)，其中 N指的是链表的节点数量。
  空间复杂度：O(N)，递归过程使用的堆栈空间。

  方法二迭代
  1. 定义亚节点dummy，当前指针p，前节点pre_node， 第一个节点first_node,
  第二个节点second_pre
  2.
  循环迭带，条件为当前指针p为不为空或者p->next不为空（即链表为空了或者只剩下一个节点了）
  3. 初始化 first_node=p, sencond_node=p->next
  4. 交换位置， pre_node->next = second_node; first_node->next =
  second_node->next; second_node->next = first_node;
  5. 更新pre_node以及p， pre_node=first_node; p = first_node->next;
  复杂度：
  时间复杂度：O(N)，其中 N指的是链表的节点数量。
  空间复杂度：O(1)
*/

#if 0
  ListNode* swapPairs(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
      return head;
    }

    ListNode* first_node = head;
    ListNode* second_node = head->next;
    first_node->next = swapPairs(second_node->next);
    second_node->next = first_node;

    return second_node;
  }
#endif

  ListNode* swapPairs(ListNode* head) {
    if (head == nullptr) {
      return head;
    }

    ListNode* dummy = new ListNode(-1);
    dummy->next = head;
    ListNode* p = head;
    ListNode* pre = dummy;
    ListNode* first_node = p;
    ListNode* second_node = p->next;

    while (p != nullptr && p->next != nullptr) {
      first_node = p;
      second_node = p->next;

      pre->next = second_node;
      first_node->next = second_node->next;
      second_node->next = first_node;

      pre = first_node;
      p = first_node->next;
    }

    return dummy->next;
  }
};

int main() {
  ListNode* p1 = new ListNode(1);
  ListNode* p2 = new ListNode(2);
  ListNode* p3 = new ListNode(3);
  ListNode* p4 = new ListNode(4);
  p1->next = p2;
  p2->next = p3;
  p3->next = p4;
  p4->next = nullptr;

  Solution sol;
  auto result = sol.swapPairs(p1);
  while (result && result->next) {
    cout << result->val << "->";
    result = result->next;
  }

  if (result) {
    cout << result->val << endl;
  }
}
