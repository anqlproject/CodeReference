// Integer-indexed directed adjacency lists; visits only vertices reachable from start.
package main

import "fmt"

func DepthFirstSearch(g [][]int, s int) []int {
	seen := make([]bool, len(g))
	st := []int{
		s,
	}
	out := []int{}
	for len(st) > 0 {
		u := st[len(st) - 1]
		st = st[:len(st) - 1]
		if seen[u] {
			continue
		}
		seen[u] = true
		out = append(out, u)
		for i := len(g[u]) - 1; i >= 0; i-- {
			st = append(st, g[u][i])
		}
	}
	return out
}

func main() {
	fmt.Println(DepthFirstSearch([][]int{
		{
			1, 2,
		},
		{
			3,
		},
		{
			3,
		},
		{
		},
	}, 0))
}
