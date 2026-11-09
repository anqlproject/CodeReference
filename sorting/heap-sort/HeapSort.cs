using System;
public static class HeapSort {
    public static int[] Sort(int[] values) {
        int[] a = (int[])values.Clone(); for (int i = a.Length / 2 - 1; i >= 0; i--) Sift(a, i, a.Length); for (int end = a.Length - 1; end > 0; end--) { Swap(a, 0, end); Sift(a, 0, end); } return a;
    }
    private static void Sift(int[] a, int root, int size) { while (2 * root + 1 < size) { int child = 2 * root + 1; if (child + 1 < size && a[child] < a[child + 1]) child++; if (a[root] >= a[child]) break; Swap(a, root, child); root = child; } }
    private static void Swap(int[] a, int i, int j) { int t = a[i]; a[i] = a[j]; a[j] = t; }
    public static void Main() { Console.WriteLine(string.Join(" ", Sort(new[] { 5, 1, 4, 2, 8 }))); }
}
