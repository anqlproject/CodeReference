package main

import "fmt"

func BubbleSort(values []int) []int {
	a := append([]int(nil), values...)
	for end := len(a) - 1; end > 0; end-- {
		swapped := false
		for i := 0; i < end; i++ {
			if a[i] > a[i + 1] {
				a[i], a[i + 1] = a[i + 1], a[i]
				swapped = true
			}
		}
		if !swapped {
			break
		}
	}
	return a
}

func main() {
	fmt.Println(BubbleSort([]int{
		5, 1, 4, 2, 8,
	}))
}
