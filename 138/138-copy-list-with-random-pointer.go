package main

type Node struct {
	Val    int
	Next   *Node
	Random *Node
}

func copyRandomList(head *Node) *Node {
	if head == nil {
		return head
	}

	m := make(map[*Node]*Node)

	node := head
	for node != nil {
		m[node] = &Node{node.Val, nil, nil}
		node = node.Next
	}

	node = head
	for node.Next != nil {
		m[node].Next = m[node.Next]
		m[node].Random = m[node.Random]
		node = node.Next
	}

	m[node].Next = nil
	m[node].Random = m[node.Random]

	return m[head]
}
