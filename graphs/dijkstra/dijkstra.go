// Weighted adjacency lists; edge weights must be nonnegative.
package main

import "fmt"

type Edge struct {
	To int
	Weight int64
}

func Dijkstra(g [][]Edge, s int) []int64 {
	d := make([]int64, len(g))
	used := make([]bool, len(g))
	for i := range d {
		d[i] = 1 << 62
	}
	d[s] = 0
	for {
		u := -1
		for i := range d {
			if !used[i] && (u < 0 || d[i] < d[u]) {
				u = i
			}
		}
		if u < 0 || d[u] == 1 << 62 {
			break
		}
		used[u] = true
		for _, e := range g[u] {
			if e.Weight < 0 {
				panic("negative edge")
			}
			if d[u] + e.Weight < d[e.To] {
				d[e.To] = d[u] + e.Weight
			}
		}
	}
	return d
}

func main() {
	fmt.Println(Dijkstra([][]Edge{
		{
			{
				1, 2,
			},
			{
				2, 5,
			},
		},
		{
			{
				2, 1,
			},
		},
		{
		},
	}, 0))
}
