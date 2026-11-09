package main

import "fmt"

func InterpolationSearch(a []int, x int) int {
	l, r := 0, len(a) - 1
	for l <= r && a[l] <= x && x <= a[r] {
		if a[l] == a[r] {
			if a[l] == x {
				return l
			}
			return -1
		}
		p := l + (x - a[l]) * (r - l) / (a[r] - a[l])
		if a[p] == x {
			return p
		}
		if a[p] < x {
			l = p + 1
		} else {
			r = p - 1
		}
	}
	return -1
}

func main() {
	fmt.Println(InterpolationSearch([]int{
		1, 2, 2, 4,
	}, 2))
}
