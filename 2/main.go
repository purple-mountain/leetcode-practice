package main

type ListNode struct {
	Val  int
	Next *ListNode
}

func getLength(head *ListNode) int {
	l := 0

	node := head
	for node != nil {
		l++
		node = node.Next
	}

	return l
}

func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	var carry int
	var head *ListNode

	if getLength(l1) > getLength(l2) {
		head = l1
	} else {
		head = l2
	}

	node := head
	var lastNode *ListNode

	for node != nil {
		var sum int
		if l1 != nil && l2 != nil {
			sum = l1.Val + l2.Val + carry
			l1 = l1.Next
			l2 = l2.Next
		} else {
			sum = node.Val + carry
		}

		node.Val = sum % 10
		carry = sum / 10
		lastNode = node
		node = node.Next
	}

	if carry != 0 {
		lastNode.Next = &ListNode{carry, nil}
	}

	return head
}
