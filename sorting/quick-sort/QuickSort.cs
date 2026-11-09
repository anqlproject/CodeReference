using System;
public static class QuickSort {
  public static int[] Sort(int[] values) {
    int[] a = (int[])values.Clone();
    if (a.Length > 0)
      QuickSort(a, 0, a.Length - 1);
    return a;
  }
  private static void QuickSort(int[] a, int lo, int hi) {
    int i = lo, j = hi, pivot = a[lo + (hi - lo) / 2];
    while (i <= j) {
      while (a[i] < pivot)
        i++;
      while (a[j] > pivot)
        j--;
      if (i <= j)
        Swap(a, i++, j--);
    }
    if (lo < j)
      QuickSort(a, lo, j);
    if (i < hi)
      QuickSort(a, i, hi);
  }
  public static void Main() {
    Console.WriteLine(string.Join(" ", Sort(new[] { 5, 1, 4, 2, 8 })));
  }
}
