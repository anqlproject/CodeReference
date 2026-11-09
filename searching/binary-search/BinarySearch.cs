using System;
public static class BinarySearch {
  public static int Search(int[] a, int x) {
    int l = 0, r = a.Length - 1;
    while (l <= r) {
      int m = l + (r - l) / 2;
      if (a[m] == x)
        return m;
      if (a[m] < x)
        l = m + 1;
      else
        r = m - 1;
    }
    return -1;
  }
  public static void Main() {
    Console.WriteLine(Search(new[] { 1, 3, 5, 7 }, 5));
  }
}
