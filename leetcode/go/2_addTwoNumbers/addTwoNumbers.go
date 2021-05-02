package leetcode

import "fmt"

type ListNode struct {
	Val  int
	Next *ListNode
}

func (l *ListNode) String() string {
	var summary string
	for l != nil {
		summary += fmt.Sprintf("%d ", l.Val)
		l = l.Next
	}

	return summary
}

func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	dummpy := &ListNode{}
	n1, n2, carry, cur := 0, 0, 0, dummpy
	for l1 != nil || l2 != nil || carry != 0 {
		if l1 == nil {
			n1 = 0
		} else {
			n1 = l1.Val
			l1 = l1.Next
		}

		if l2 == nil {
			n2 = 0
		} else {
			n2 = l2.Val
			l2 = l2.Next
		}

		cur.Next = &ListNode{
			Val: (n1 + n2 + carry) % 10,
		}
		cur = cur.Next
		carry = (n1 + n2 + carry) / 10
	}

	return dummpy.Next
}
