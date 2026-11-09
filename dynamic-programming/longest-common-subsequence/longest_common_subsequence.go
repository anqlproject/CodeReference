package main

import "fmt"

func LongestCommonSubsequence(a, b string) int {
	d := make([]int, len(b) + 1)
	for _, x := range a {
		p := 0
		for j := 1; j <= len(b); j++ {
			o := d[j]
			if byte(x) == b[j - 1] {
				d[j] = p + 1
			} else if d[j - 1] > d[j] {
				d[j] = d[j - 1]
			}
			p = o
		}
	}
	return d[len(b)]
}

func main() {
	fmt.Println(LongestCommonSubsequence("ABCBDAB", "BDCAB"))
}
