package main

import "fmt"

type ListNode struct {
	Val  int
	Next *ListNode
}

/*
func swapPairs(head *ListNode) *ListNode {
	if nil == head || nil == head.Next {
		return head
	}

	newHead := head.Next
	head.Next = swapPairs(newHead.Next)
	newHead.Next = head

	return newHead
}
*/

func swapPairs(head *ListNode) *ListNode {
	dummy := &ListNode{
		Val:  -1,
		Next: head,
	}

	pre := dummy
	cur := dummy.Next
	for cur != nil && cur.Next != nil {
		next := cur.Next
		pre.Next = next
		cur.Next = next.Next
		next.Next = cur
		pre = cur
		cur = cur.Next
	}

	return dummy.Next
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

	h := swapPairs(p1)
	for h != nil {
		fmt.Printf("%d ", h.Val)
		h = h.Next
	}

	fmt.Println()
}
