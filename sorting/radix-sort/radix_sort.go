package main

import "fmt"

func RadixSort(values []int) []int {
	a := append([]int(nil), values...)
	max := 0
	for _, v := range a {
		if v < 0 {
			panic("radix sort supports non-negative integers only")
		}
		if v > max {
			max = v
		}
	}
	out := make([]int, len(a))
	for exp := 1; max / exp > 0; exp *= 10 {
		count := [10]int {
		}
		for _, v := range a {
			count[(v / exp) % 10]++
		}
		for i := 1; i < 10; i++ {
			count[i] += count[i - 1]
		}
		for i := len(a) - 1; i >= 0; i-- {
			d := (a[i] / exp) % 10
			count[d]--
			out[count[d]] = a[i]
		}
		copy(a, out)
	}
	return a
}

func main() {
	fmt.Println(RadixSort([]int{
		5, 1, 4, 2, 8,
	}))
}
