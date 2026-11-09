using System;
public static class ShellSort {
  public static int[] Sort(int[] values) {
    int[] a = (int[])values.Clone();
    for (int gap = a.Length / 2; gap > 0; gap /= 2)
      for (int i = gap; i < a.Length; i++) {
        int v = a[i], j = i;
        while (j >= gap && a[j - gap] > v) {
          a[j] = a[j - gap];
          j -= gap;
        }
        a[j] = v;
      }
    return a;
  }
  public static void Main() {
    Console.WriteLine(string.Join(" ", Sort(new[] { 5, 1, 4, 2, 8 })));
  }
}
