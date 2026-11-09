package main

import "fmt"

func BucketSort(values []int) []int {
    a := append([]int(nil), values...); if len(a) < 2 { return a }; min, max := a[0], a[0]; for _, v := range a { if v < min { min = v }; if v > max { max = v } }; if min == max { return a }; buckets := make([][]int, len(a)); span := max-min+1; for _, v := range a { b := (v-min)*len(a)/span; if b >= len(a) { b = len(a)-1 }; buckets[b] = append(buckets[b], v) }; k := 0; for _, bucket := range buckets { for i := 1; i < len(bucket); i++ { v, j := bucket[i], i-1; for j >= 0 && bucket[j] > v { bucket[j+1] = bucket[j]; j-- }; bucket[j+1] = v }; for _, v := range bucket { a[k] = v; k++ } }; return a
}

func main() { fmt.Println(BucketSort([]int{5, 1, 4, 2, 8})) }
