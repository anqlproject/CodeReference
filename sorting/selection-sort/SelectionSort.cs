using System;
public static class SelectionSort {
  public static int[] Sort(int[] values) {
    int[] a = (int[])values.Clone();
    for (int i = 0; i < a.Length; i++) {
      int min = i;
      for (int j = i + 1; j < a.Length; j++)
        if (a[j] < a[min])
          min = j;
      int t = a[i];
      a[i] = a[min];
      a[min] = t;
    }
    return a;
  }
  public static void Main() {
    Console.WriteLine(string.Join(" ", Sort(new[] { 5, 1, 4, 2, 8 })));
  }
}
