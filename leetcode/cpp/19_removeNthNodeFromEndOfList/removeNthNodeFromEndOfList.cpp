//
// Created by kayxhding on 2020-04-21 22:02:46
//
/*
 Given a linked list, remove the n-th node from the end of list and return its
head.

Example:

Given linked list: 1->2->3->4->5, and n = 2.

After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:

Given n will always be valid.

Follow up:

Could you do this in one pass?
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
  方法一：两次遍历算法
  1.
  添加一个哑结点作为辅助，该结点位于列表头部。哑结点用来简化某些极端情况，例如列表中只含有一个结点，或需要删除列表的头部
  2. 在第一次遍历中，我们找出列表的长度 L
  3. 然后设置一个指向哑结点的指针，并移动它遍历列表，直至它到达第 (L - n)
  个结点那里。我们把第 (L - n) 个结点的 next 指针重新链接至第 (L - n + 2)
  个结点，完成这个算法。

  复杂度分析
  时间复杂度：O(L)
  空间复杂度：O(1)O(1)

  方法二： 一次遍历算法
  1.
  添加一个哑结点作为辅助，该结点位于列表头部。哑结点用来简化某些极端情况，例如列表中只含有一个结点，或需要删除列表的头部
  2. 第一个指针从列表的开头向前移动 n+1 步
  3. 第二个指针将从列表的开头出发,现在，这两个指针被 nn 个结点分开
  4. 同时移动两个指针向前来保持这个恒定的间隔，直到第一个指针到达最后一个结点
  5. 重新链接第二个指针所引用的结点的 next 指针指向该结点的下下个结点

  复杂度分析
  时间复杂度：O(L)，该算法对含有 L个结点的列表进行了一次遍历。因此时间复杂度为
  O(L)。 空间复杂度：O(1)，我们只用了常量级的额外空间。
*/
#if 0
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    int len = 0;
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* p = head;

    while (p != nullptr) {
      p = p->next;
      ++len;
    }

    p = dummy;
    len -= n;
    while (len > 0) {
      p = p->next;
      --len;
    }

    p->next = p->next->next;

    return dummy->next;
  }
#endif
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* dummpy = new ListNode(0);
    dummpy->next = head;
    ListNode* first = dummpy;
    ListNode* second = dummpy;
    while (n + 1 > 0) {
      first = first->next;
      --n;
    }

    while (first != nullptr) {
      first = first->next;
      second = second->next;
    }

    second->next = second->next->next;

    return dummpy->next;
  }
};

int main() {
  ListNode* p1 = new ListNode(1);
  ListNode* p2 = new ListNode(2);
  ListNode* p3 = new ListNode(3);
  ListNode* p4 = new ListNode(4);
  ListNode* p5 = new ListNode(5);
  p1->next = p2;
  p2->next = p3;
  p3->next = p4;
  p4->next = p5;

  Solution sol;
  auto l = sol.removeNthFromEnd(p1, 2);
  while (l != nullptr) {
    cout << l->val << " ";
    l = l->next;
  }
  cout << endl;
}
