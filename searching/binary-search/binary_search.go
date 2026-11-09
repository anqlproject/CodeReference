package main

import "fmt"

func BinarySearch(a []int, x int) int {
	l, r := 0, len(a) - 1
	for l <= r {
		m := l + (r - l) / 2
		if a[m] == x {
			return m
		}
		if a[m] < x {
			l = m + 1
		} else {
			r = m - 1
		}
	}
	return -1
}

func main() {
	fmt.Println(BinarySearch([]int{
		1, 3, 5, 7,
	}, 5))
}
