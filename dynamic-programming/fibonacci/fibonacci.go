package main

import "fmt"

func Fibonacci(n int) int64 {
	if n < 0 {
		panic("negative n")
	}
	a, b := int64(0), int64(1)
	for i := 0; i < n; i++ {
		a, b = b, a + b
	}
	return a
}

func main() {
	fmt.Println(Fibonacci(10))
}
