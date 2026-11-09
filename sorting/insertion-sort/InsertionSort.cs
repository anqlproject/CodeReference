using System;
public static class InsertionSort {
  public static int[] Sort(int[] values) {
    int[] a = (int[])values.Clone();
    for (int i = 1; i < a.Length; i++) {
      int v = a[i], j = i - 1;
      while (j >= 0 && a[j] > v) {
        a[j + 1] = a[j];
        j--;
      }
      a[j + 1] = v;
    }
    return a;
  }
  public static void Main() {
    Console.WriteLine(string.Join(" ", Sort(new[] { 5, 1, 4, 2, 8 })));
  }
}
