//
// Created by kayxhding on 2020-06-22 22:55:49
//

/*
   Reverse a linked list from position m to n. Do it in one-pass.

Note: 1 ≤ m ≤ n ≤ length of list.

Example:

Input: 1->2->3->4->5->NULL, m = 2, n = 4
Output: 1->4->3->2->5->NULL

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
  1.
  找到要反转链表的头指针，记录该头指针的前向指针reverseHeadPre，该头指针反转后即为该段链表的的尾指针为ListNode*
  reverseTail = node;
  2. 遍历 n - m + 1次，翻转链表, 记录翻转链表的头指针
  3. 连接翻转后的头指针、尾指针，若reverseHeadPre ！= nullptr,
  则reverseHeadPre->next = reverseHead
  4. 若reverseHeadPre == nullptr，  dummy->next = reverseHead;
  5.  reverseTail->next = nodeNext;
  复杂度：
  时间复杂度：O(n)
  空间复杂度：O(1)
*/
  ListNode *reverseBetween(ListNode *head, int m, int n) {
    ListNode *dummy = new ListNode(0);
    dummy->next = head;

    ListNode *preNode = nullptr;
    ListNode *node = head;

    for (int i = 1; i < m; ++i) {
      preNode = node;
      node = node->next;
    }

    ListNode *reversePreHead = preNode;
    ListNode *reverseHead = nullptr;
    ListNode *reverseTail = node;
    ListNode *nextNode = nullptr;

    for (int i = 0; i < n - m + 1; ++i) {
      nextNode = node->next;
      if (i == n - m) {
        reverseHead = node;
      }

      node->next = preNode;
      preNode = node;
      node = nextNode;
    }

    if (reversePreHead) {
      reversePreHead->next = reverseHead;
    } else {
      dummy->next = reverseHead;
    }

    if (reverseTail) {
      reverseTail->next = nextNode;
    }

    return dummy->next;
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

  Solution sol;
  auto result = sol.reverseBetween(p1, 1, 5);
  while (result) {
    cout << result->val << " ";
    result = result->next;
  }
  cout << endl;
}
