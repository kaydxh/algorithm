//
// Created by kayxhding on 2020-04-20 23:03:44
//

/*
Reverse a singly linked list.

Example:

Input: 1->2->3->4->5->NULL
Output: 5->4->3->2->1->NULL
Follow up:

A linked list can be reversed either iteratively or recursively. Could you
implement both?
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
    /*
    1. 定义一个当前节点指针node，上一个节点指针pre
    2. 遍历node,
    获取node的下一个指针nodenext，判断nodenext是否为nullptr，若是node保存为反转后的头指针
    3. 当前node的next指向pre
    4. 更新pre和node， pre=node， node=nodeNext
    复杂度：
    1. 时间复杂度O(n)
    2. 空间复杂度O(1)
    */
    /*
 ListNode *reverseList(ListNode *head) {
   ListNode *reversedHead = nullptr;
   ListNode *node = head;
   ListNode *pre = nullptr;

   while (node != nullptr) {
     ListNode *nextNode = node->next;
     if (nextNode == nullptr) {
       reversedHead = node;
     }

     node->next = pre;
     pre = node;
     node = nextNode;
   }

   return reversedHead;
 }
 */
    ListNode *reverseList(ListNode *head) {
        if (head == nullptr) {
            return nullptr;
        }

        ListNode *pre = nullptr;
        ListNode *cur = head;

        while (cur) {
            ListNode *nextNode = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nextNode;
        }

        return pre;
    }
};

int main() {
    ListNode *p1 = new ListNode(1);
    ListNode *p2 = new ListNode(2);
    ListNode *p3 = new ListNode(3);
    ListNode *p4 = new ListNode(4);
    ListNode *p5 = new ListNode(5);
    p1->next = p2;
    p2->next = p3;
    p3->next = p4;
    p4->next = p5;
    p5->next = nullptr;

    Solution sol;
    auto h = sol.reverseList(p1);
    while (h != nullptr) {
        cout << h->val << " ";
        h = h->next;
    }

    cout << endl;
}
