using System;
public static class BubbleSort {
    public static int[] Sort(int[] values) {
        int[] a = (int[])values.Clone();
        for (int end = a.Length - 1; end > 0; end--) { bool swapped = false; for (int i = 0; i < end; i++) if (a[i] > a[i + 1]) { int t = a[i]; a[i] = a[i + 1]; a[i + 1] = t; swapped = true; } if (!swapped) break; } return a;
    }
    public static void Main() { Console.WriteLine(string.Join(" ", Sort(new[] { 5, 1, 4, 2, 8 }))); }
}
