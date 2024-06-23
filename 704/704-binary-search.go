package main

func search(nums []int, target int) int {
	low, high := 0, len(nums)

	for low < high {
		middle := (low + high) / 2

		if nums[middle] == target {
			return middle
		} else if nums[middle] > target {
			high = middle
		} else {
			low = middle + 1
		}
	}

	return -1
}
