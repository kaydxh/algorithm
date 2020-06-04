//
// Created by kayxhding on 2020-06-04 22:04:53
//

/*
   Given a sorted linked list, delete all nodes that have duplicate numbers,
leaving only distinct numbers from the original list.

Return the linked list sorted as well.

Example 1:

Input: 1->2->3->3->4->4->5
Output: 1->2->5
Example 2:

Input: 1->1->1->2->3
Output: 2->3
*/

#include <iostream>

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
 public:
  /*
  迭代法
  1. 一个指针 pre 代表重复数字的前边的一个指针，另一个指针 cur 用来遍历链表
  2. cur 和 cur.next 相等，cur 不停后移
  3. 发生了相等的情况，  pre->next 直接指向 cur->next
  删除所有重复数字，这里cur->next只是暂时加入pre链表，如果cur->next->val ==
  cur->next->next->val, 那么pre->next
  在下一次迭代中又会更新为cur->next->next,机，之前的cur->next又被移除了
  4. 若没有发生相等的情况， pre->next =
  cur,且pre更新为pre->next，即真正到不发生相等的情况时，才会移动pre，真正把cur加入到最终链表里

  复杂度：
  时间复杂度：O(n)
  空间复杂度：O(1)
  */

#if 0
  ListNode* deleteDuplicates(ListNode* head) {
    ListNode* preNode = new ListNode(0);
    ListNode* dummy = preNode;
    dummy->next = preNode;

    ListNode* curNode = head;
    bool equal = false;
    while (curNode != nullptr && curNode->next != nullptr) {
      while (curNode != nullptr && curNode->next != nullptr &&
             curNode->val == curNode->next->val) {
        curNode = curNode->next;
        equal = true;
      }

      if (equal) {
        preNode->next = curNode->next;
        equal = false;
      } else {
        preNode->next = curNode;
        preNode = preNode->next;
      }

      curNode = curNode->next;
    }

    return dummy->next;
  }
#endif

  /*
  递归：
  1. 头结点和后边的节点相等，跳过所有重复数字， 将所有重复数字去掉后，进入递归
  2. 头结点和后边的节点不相等， 保留头结点，后边的所有节点进入递归
  3. 返回头指针
*/

  ListNode* deleteDuplicates(ListNode* head) {
    if (head == nullptr) {
      return nullptr;
    }

    if (head != nullptr && head->next != nullptr &&
        head->val == head->next->val) {
      while (head != nullptr && head->next != nullptr &&
             head->val == head->next->val) {
        head = head->next;
      }

      return deleteDuplicates(head->next);
    } else {
      head->next = deleteDuplicates(head->next);
    }

    return head;
  }
};

int main() {
  ListNode* p1 = new ListNode(1);
  ListNode* p2 = new ListNode(2);
  ListNode* p3 = new ListNode(3);
  ListNode* p4 = new ListNode(3);
  ListNode* p5 = new ListNode(4);
  ListNode* p6 = new ListNode(4);
  ListNode* p7 = new ListNode(5);

  p1->next = p2;
  p2->next = p3;
  p3->next = p4;
  p4->next = p5;
  p5->next = p6;
  p6->next = p7;
  p7->next = nullptr;

  Solution sol;
  auto result = sol.deleteDuplicates(p1);
  while (result != nullptr) {
    std::cout << result->val << " ";
    result = result->next;
  }
  std::cout << std::endl;
}
