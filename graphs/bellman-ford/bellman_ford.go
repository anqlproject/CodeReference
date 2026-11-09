// Directed weighted edge list; negative weights are allowed; reachable negative cycles are reported.
package main

import "fmt"

type Edge struct {
	From, To int
	Weight int64
}

func BellmanFord(n int, es []Edge, s int) []int64 {
	d := make([]int64, n)
	for i := range d {
		d[i] = 1 << 62
	}
	d[s] = 0
	for i := 1; i < n; i++ {
		c := false
		for _, e := range es {
			if d[e.From] != 1 << 62 && d[e.From] + e.Weight < d[e.To] {
				d[e.To] = d[e.From] + e.Weight
				c = true
			}
		}
		if !c {
			break
		}
	}
	for _, e := range es {
		if d[e.From] != 1 << 62 && d[e.From] + e.Weight < d[e.To] {
			panic("reachable negative cycle")
		}
	}
	return d
}

func main() {
	fmt.Println(BellmanFord(3, []Edge{
		{
			0, 1, 4,
		},
		{
			0, 2, 5,
		},
		{
			1, 2, -2,
		},
	}, 0))
}
