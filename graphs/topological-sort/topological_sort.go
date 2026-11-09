// Directed adjacency lists; returns no ordering when a directed cycle exists.
package main

import "fmt"

func TopologicalSort(g [][]int)([]int, bool) {
	d := make([]int, len(g))
	for _, row := range g {
		for _, v := range row {
			d[v]++
		}
	}
	q := []int{}
	for i, x := range d {
		if x == 0 {
			q = append(q, i)
		}
	}
	out := []int{}
	for i := 0; i < len(q); i++ {
		u := q[i]
		out = append(out, u)
		for _, v := range g[u] {
			d[v]--
			if d[v] == 0 {
				q = append(q, v)
			}
		}
	}
	return out, len(out) == len(g)
}

func main() {
	fmt.Println(TopologicalSort([][]int{
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
	}))
}
