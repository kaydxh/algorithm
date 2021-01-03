package main

import "fmt"

type ListNode struct {
	Val  int
	Next *ListNode
}

func hasCycle(head *ListNode) bool {
	fast := head
	slow := head
	for fast != nil && fast.Next != nil && slow != nil {
		fast = fast.Next.Next
		slow = slow.Next

		if fast == slow {
			return true
		}
	}

	return false

}

func main() {
	p1 := &ListNode{
		Val: 3,
	}
	p2 := &ListNode{
		Val: 2,
	}
	p3 := &ListNode{
		Val: 0,
	}
	p4 := &ListNode{
		Val: -4,
	}

	p1.Next = p2
	p2.Next = p3
	p3.Next = p4
	p4.Next = p2

	cycled := hasCycle(p1)
	fmt.Println(cycled)
}
