package main

import "fmt"

func SelectionSort(values []int) []int {
	a := append([]int(nil), values...)
	for i := range a {
		min := i
		for j := i + 1; j < len(a); j++ {
			if a[j] < a[min] {
				min = j
			}
		}
		a[i], a[min] = a[min], a[i]
	}
	return a
}

func main() {
	fmt.Println(SelectionSort([]int{
		5, 1, 4, 2, 8,
	}))
}
