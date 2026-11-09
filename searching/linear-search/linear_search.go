package main

import "fmt"

func LinearSearch(a []int, x int) int {
	for i, v := range a {
		if v == x {
			return i
		}
	}
	return -1
}

func main() {
	fmt.Println(LinearSearch([]int{
		4, 2, 7,
	}, 2))
}
