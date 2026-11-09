// Undirected weighted edge list; returns failure when the graph is disconnected.
package main

import "fmt"

type Edge struct {
	U, V int
	W int64
}

func Kruskal(n int, es []Edge)(int64, bool) {
	p := make([]int, n)
	for i := range p {
		p[i] = i
	}
	var find func(int) int
	find = func(x int) int {
		if p[x] != x {
			p[x] = find(p[x])
		}
		return p[x]
	}
	chosen := 0
	var total int64
	for len(es) > 0 {
		m := 0
		for i := 1; i < len(es); i++ {
			if es[i].W < es[m].W {
				m = i
			}
		}
		e := es[m]
		es = append(es[:m], es[m + 1:]...)
		a, b := find(e.U), find(e.V)
		if a != b {
			p[a] = b
			total += e.W
			chosen++
		}
	}
	return total, chosen == max(0, n - 1)
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func main() {
	v, ok := Kruskal(3, []Edge{
		{
			0, 1, 4,
		},
		{
			1, 2, 2,
		},
		{
			0, 2, 5,
		},
	})
	fmt.Println(v, ok)
}
