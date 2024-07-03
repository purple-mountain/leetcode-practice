package main

type Node struct {
	Key  int
	Val  int
	Next *Node
	Prev *Node
}

type LRUCache struct {
	Capacity int
	Length   int
	Cache    map[int]*Node
	LRU      *Node
	MRU      *Node
}

func Constructor(capacity int) LRUCache {
	return LRUCache{capacity, 0, make(map[int]*Node), nil, nil}
}

func (this *LRUCache) Get(key int) int {
	res := this.Cache[key]

	if res == nil {
		return -1
	}

	if res == this.MRU {
		return res.Val
	}

	if res == this.LRU {
		this.LRU = res.Prev
		this.LRU.Next = nil
	} else {
		res.Prev.Next = res.Next
		res.Next.Prev = res.Prev
	}

	res.Prev = nil
	res.Next = this.MRU
	this.MRU.Prev = res
	this.MRU = res

	return res.Val
}

func (this *LRUCache) Put(key int, value int) {
	if this.Cache[key] != nil {
		node := this.Cache[key]
		node.Val = value

		if node == this.MRU {
			return
		}

		if node == this.LRU {
			this.LRU = this.LRU.Prev
			node.Prev.Next = node.Next
		} else {
			node.Prev.Next = node.Next
			node.Next.Prev = node.Prev
		}

		node.Prev = nil
		node.Next = this.MRU
		this.MRU.Prev = node
		this.MRU = node

		return
	}

	this.Length++

	node := &Node{key, value, this.MRU, nil}

	if this.MRU == nil && this.LRU == nil {
		this.LRU = node
		this.MRU = node
	} else {
		this.MRU.Prev = node
		this.MRU = node
	}

	if this.Length > this.Capacity {
		this.Length--
		rmvNode := this.LRU
		this.LRU = rmvNode.Prev
		this.Cache[rmvNode.Key] = nil
		this.LRU.Next = nil
		rmvNode.Prev = nil
	}

	this.Cache[key] = node
}
