using System;
using System.Linq;
public static class RadixSort {
    public static int[] Sort(int[] values) {
        int[] a = (int[])values.Clone(); foreach (int v in a) if (v < 0) throw new ArgumentException("radix sort supports non-negative integers only"); int max = a.Length == 0 ? 0 : a.Max(); int[] output = new int[a.Length]; for (long exp = 1; max / exp > 0; exp *= 10) { int[] count = new int[10]; foreach (int v in a) count[(int)((v / exp) % 10)]++; for (int i = 1; i < 10; i++) count[i] += count[i - 1]; for (int i = a.Length - 1; i >= 0; i--) { int d = (int)((a[i] / exp) % 10); output[--count[d]] = a[i]; } int[] t = a; a = output; output = t; } return a;
    }
    public static void Main() { Console.WriteLine(string.Join(" ", Sort(new[] { 5, 1, 4, 2, 8 }))); }
}
