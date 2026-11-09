package main

import "fmt"

func ShellSort(values []int) []int {
    a := append([]int(nil), values...)
    for gap := len(a)/2; gap > 0; gap /= 2 { for i := gap; i < len(a); i++ { v, j := a[i], i; for j >= gap && a[j-gap] > v { a[j] = a[j-gap]; j -= gap }; a[j] = v } }; return a
}

func main() { fmt.Println(ShellSort([]int{5, 1, 4, 2, 8})) }
