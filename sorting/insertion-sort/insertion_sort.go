package main

import "fmt"

func InsertionSort(values []int) []int {
	a := append([]int(nil), values...)
	for i := 1; i < len(a); i++ {
		v, j := a[i], i - 1
		for j >= 0 && a[j] > v {
			a[j + 1] = a[j]
			j--
		}
		a[j + 1] = v
	}
	return a
}

func main() {
	fmt.Println(InsertionSort([]int{
		5, 1, 4, 2, 8,
	}))
}
