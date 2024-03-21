//
// Created by kayxhding on 2024-03-21 14:11:42
//
/*
 * You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.

Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]
Example 2:

Input: list1 = [], list2 = []
Output: []
Example 3:

Input: list1 = [], list2 = [0]
Output: [0]


Constraints:

The number of nodes in both lists is in the range [0, 50].
-100 <= Node.val <= 100
Both list1 and list2 are sorted in non-decreasing order.
*/

//时间复杂度：O(n+m)O(n + m)O(n+m)
//空间复杂度：O(1)O(1)O(1)

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
//递归
//时间复杂度：O(n+m)
//空间复杂度：O(n+m)
     ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
         if (l1 == nullptr) {
             return l2;
         }
         if (l2 == nullptr) {
             return l1;
         }

         ListNode *mergedHead = nullptr;
         if (l1->val < l2->val) {
             mergedHead  = l1;
             mergedHead->next = mergeTwoLists(l1->next, l2);
         } else {
             mergedHead = l2;
             mergedHead -> next = mergeTwoLists(l1, l2->next);
         }

         return mergedHead;
     }
#endif
// 迭代
//时间复杂度：O(n+m)
//空间复杂度：O(1)
     ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
         ListNode *dummpy = new ListNode(0);
         ListNode *pre = dummpy;
         while (l1!= nullptr && l2!= nullptr) {
             if (l1->val < l2->val) {
                 pre->next = l1;
                 l1 = l1->next;
             } else {
                 pre->next = l2;
                 l2 = l2->next;
             }
             // 注意这里需要更新pre，为下一次循环复制做准备, 才能把链路链接起来
             pre = pre->next;
         }
         pre->next = l1 == nullptr ? l2 : l1;
         return dummpy->next;
     }
};


int main() {
    ListNode* l1 = new ListNode(1);
    ListNode* l2 = new ListNode(2);
    ListNode* l3 = new ListNode(4);
    ListNode* p1 = new ListNode(1);
    ListNode* p2 = new ListNode(3);
    ListNode* p3 = new ListNode(4);
    l1->next = l2;
    l2->next = l3;
    p2->next = p3;
    p1->next = p2;
    p2->next = p3;

    Solution sol;
    auto l = sol. mergeTwoLists(l1, p1);
    while (l != nullptr) {
        cout << l->val << " ";
        l = l->next;
    }
    cout << endl;
}
