// Integer-indexed directed adjacency lists; visits only vertices reachable from start.
package main

import "fmt"

func BreadthFirstSearch(g [][]int, s int) []int {
	seen := make([]bool, len(g))
	seen[s] = true
	q := []int{
		s,
	}
	out := []int{}
	for i := 0; i < len(q); i++ {
		u := q[i]
		out = append(out, u)
		for _, v := range g[u] {
			if !seen[v] {
				seen[v] = true
				q = append(q, v)
			}
		}
	}
	return out
}

func main() {
	fmt.Println(BreadthFirstSearch([][]int{
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
