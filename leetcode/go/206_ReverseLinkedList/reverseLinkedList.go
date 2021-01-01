package main

import "fmt"

type ListNode struct {
	Val  int
	Next *ListNode
}

func reverseList(head *ListNode) *ListNode {
	cur := head
	var pre *ListNode

	for cur != nil {
		next := cur.Next
		cur.Next = pre
		pre = cur
		cur = next
	}

	return pre

}

func main() {
	p1 := &ListNode{
		Val: 1,
	}
	p2 := &ListNode{
		Val: 2,
	}
	p3 := &ListNode{
		Val: 3,
	}
	p4 := &ListNode{
		Val: 4,
	}
	p5 := &ListNode{
		Val: 5,
	}
	p1.Next = p2
	p2.Next = p3
	p3.Next = p4
	p4.Next = p5

	h := reverseList(p1)

	for h != nil {
		fmt.Printf("%d ", h.Val)
		//fmt.Printf("%v\n", h)
		h = h.Next
	}

	fmt.Println()

}
