package main

import "fmt"

func Knapsack(w, v []int, c int) int {
	if c < 0 {
		panic("negative capacity")
	}
	d := make([]int, c + 1)
	for i, x := range w {
		if x < 0 {
			panic("negative weight")
		}
		for j := c; j >= x; j-- {
			if d[j - x] + v[i] > d[j] {
				d[j] = d[j - x] + v[i]
			}
		}
	}
	return d[c]
}

func main() {
	fmt.Println(Knapsack([]int{
		2, 3, 4,
	}, []int{
		4, 5, 6,
	}, 5))
}
