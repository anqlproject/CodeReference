package main

import "fmt"

func EuclideanGCD(a, b int) int {
	if a < 0 {
		a = -a
	}
	if b < 0 {
		b = -b
	}
	for b != 0 {
		a, b = b, a % b
	}
	return a
}

func main() {
	fmt.Println(EuclideanGCD(48, 18))
}
