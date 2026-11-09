// Weighted adjacency lists require nonnegative weights; heuristic estimates remaining cost.
package main

import "fmt"

type Edge struct {
	To int
	Weight int
}

func AStar(g [][]Edge, s, goal int, h func(int) int) int {
	d := make([]int, len(g))
	used := make([]bool, len(g))
	for i := range d {
		d[i] = int(^uint(0) >> 1)
	}
	d[s] = 0
	for {
		u := -1
		for i := range g {
			if !used[i] && d[i] < int(^uint(0) >> 1) && (u < 0 || d[i] + h(i) < d[u] + h(u)) {
				u = i
			}
		}
		if u < 0 {
			return -1
		}
		if u == goal {
			return d[u]
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
}

func main() {
	fmt.Println(AStar([][]Edge{
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
	}, 0, 2, func(int) int {
		return 0
	}))
}
