package main

import "fmt"

func CountingSort(values []int) []int {
    // The integer range must be small enough for its count array to fit in memory.
    if len(values) == 0 { return []int{} }; min, max := values[0], values[0]; for _, v := range values { if v < min { min = v }; if v > max { max = v } }; counts := make([]int, max-min+1); for _, v := range values { counts[v-min]++ }; result := make([]int, len(values)); k := 0; for i, count := range counts { for ; count > 0; count-- { result[k] = i+min; k++ } }; return result
}

func main() { fmt.Println(CountingSort([]int{5, 1, 4, 2, 8})) }
