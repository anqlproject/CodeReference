package main

import "fmt"

func sift(a []int, root, size int) {
	for 2 * root + 1 < size {
		child := 2 * root + 1
		if child + 1 < size && a[child] < a[child + 1] {
			child++
		}
		if a[root] >= a[child] {
			break
		}
		a[root], a[child] = a[child], a[root]
		root = child
	}
}

func HeapSort(values []int) []int {
	a := append([]int(nil), values...)
	for i := len(a) / 2 - 1; i >= 0; i-- {
		sift(a, i, len(a))
	}
	for end := len(a) - 1; end > 0; end-- {
		a[0], a[end] = a[end], a[0]
		sift(a, 0, end)
	}
	return a
}

func main() {
	fmt.Println(HeapSort([]int{
		5, 1, 4, 2, 8,
	}))
}
