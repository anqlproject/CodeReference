package main

import "fmt"

func SieveOfEratosthenes(n int) []int {
	if n < 2 {
		return []int{}
	}
	p := make([]bool, n + 1)
	for i := 2; i <= n; i++ {
		p[i] = true
	}
	for i := 2; i * i <= n; i++ {
		if p[i] {
			for j := i * i; j <= n; j += i {
				p[j] = false
			}
		}
	}
	out := []int{}
	for i := 2; i <= n; i++ {
		if p[i] {
			out = append(out, i)
		}
	}
	return out
}

func main() {
	fmt.Println(SieveOfEratosthenes(30))
}
