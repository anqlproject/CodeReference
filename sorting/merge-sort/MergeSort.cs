using System;
public static class MergeSort {
    public static int[] Sort(int[] values) {
        int[] a = (int[])values.Clone(); MergeSort(a, new int[a.Length], 0, a.Length); return a;
    }
    private static void MergeSort(int[] a, int[] temp, int lo, int hi) { if (hi - lo < 2) return; int mid = lo + (hi - lo) / 2; MergeSort(a, temp, lo, mid); MergeSort(a, temp, mid, hi); int i = lo, j = mid, k = lo; while (i < mid || j < hi) temp[k++] = j == hi || (i < mid && a[i] <= a[j]) ? a[i++] : a[j++]; Array.Copy(temp, lo, a, lo, hi - lo); }
    public static void Main() { Console.WriteLine(string.Join(" ", Sort(new[] { 5, 1, 4, 2, 8 }))); }
}
