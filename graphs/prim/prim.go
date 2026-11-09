// Undirected weighted adjacency lists; returns failure when the graph is disconnected.
package main

import "fmt"

type Edge struct {
	To int
	W int64
}

func Prim(g [][]Edge, s int)(int64, bool) {
	if len(g) == 0 {
		return 0, true
	}
	seen := make([]bool, len(g))
	seen[s] = true
	count := 1
	var total int64
	for count < len(g) {
		u, v := -1, -1
		var w int64
		for i := range g {
			if seen[i] {
				for _, e := range g[i] {
					if !seen[e.To] && (u < 0 || e.W < w) {
						u, v, w = i, e.To, e.W
					}
				}
			}
		}
		if u < 0 {
			return 0, false
		}
		seen[v] = true
		count++
		total += w
	}
	return total, true
}

func main() {
	v, ok := Prim([][]Edge{
		{
			{
				1, 4,
			},
			{
				2, 5,
			},
		},
		{
			{
				0, 4,
			},
			{
				2, 2,
			},
		},
		{
			{
				0, 5,
			},
			{
				1, 2,
			},
		},
	}, 0)
	fmt.Println(v, ok)
}
