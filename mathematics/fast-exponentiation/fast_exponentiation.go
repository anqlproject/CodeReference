package main

import "fmt"

func FastExponentiation(b int64, e int) float64 {
	if e < 0 {
		return 1 / FastExponentiation(b, -e)
	}
	r := int64(1)
	for e > 0 {
		if e & 1 != 0 {
			r *= b
		}
		b *= b
		e >>= 1
	}
	return float64(r)
}

func main() {
	fmt.Println(FastExponentiation(2, 10))
}
