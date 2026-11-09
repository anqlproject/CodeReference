package main

import "fmt"

func mergeSort(a, tmp []int, lo, hi int) { if hi-lo < 2 { return }; mid := lo+(hi-lo)/2; mergeSort(a,tmp,lo,mid); mergeSort(a,tmp,mid,hi); i,j,k := lo,mid,lo; for i < mid || j < hi { if j == hi || (i < mid && a[i] <= a[j]) { tmp[k] = a[i]; i++ } else { tmp[k] = a[j]; j++ }; k++ }; copy(a[lo:hi],tmp[lo:hi]) }

func MergeSort(values []int) []int {
    a := append([]int(nil), values...); temp := make([]int, len(a)); mergeSort(a, temp, 0, len(a)); return a
}

func main() { fmt.Println(MergeSort([]int{5, 1, 4, 2, 8})) }
