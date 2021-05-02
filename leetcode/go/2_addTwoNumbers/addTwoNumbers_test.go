package leetcode

import "testing"

func TestTwoSum(t *testing.T) {
	l11 := &ListNode{
		Val: 2,
	}
	l12 := &ListNode{
		Val: 4,
	}
	l13 := &ListNode{
		Val: 3,
	}
	l11.Next = l12
	l12.Next = l13

	l21 := &ListNode{
		Val: 5,
	}
	l22 := &ListNode{
		Val: 6,
	}
	l23 := &ListNode{
		Val: 4,
	}
	l21.Next = l22
	l22.Next = l23

	sumList := addTwoNumbers(l11, l21)
	t.Logf("sumList: %v", sumList)

}
