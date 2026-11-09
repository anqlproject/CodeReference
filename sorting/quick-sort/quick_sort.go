package main

import "fmt"

func quickSort(a []int, lo, hi int) {
	i, j := lo, hi
	pivot := a[lo + (hi - lo) / 2]
	for i <= j {
		for a[i] < pivot {
			i++
		}
		for a[j] > pivot {
			j--
		}
		if i <= j {
			a[i], a[j] = a[j], a[i]
			i++
			j--
		}
	}
	if lo < j {
		quickSort(a, lo, j)
	}
	if i < hi {
		quickSort(a, i, hi)
	}
}

func QuickSort(values []int) []int {
	a := append([]int(nil), values...)
	if len(a) > 0 {
		quickSort(a, 0, len(a) - 1)
	}
	return a
}

func main() {
	fmt.Println(QuickSort([]int{
		5, 1, 4, 2, 8,
	}))
}
