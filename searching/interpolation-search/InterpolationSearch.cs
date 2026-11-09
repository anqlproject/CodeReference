// Input is sorted ascending; when duplicates occur, any matching index may be
// returned.
using System;
public static class InterpolationSearch {
  public static int Search(int[] a, int x) {
    int l = 0, r = a.Length - 1;
    while (l <= r && a[l] <= x && x <= a[r]) {
      if (a[l] == a[r])
        return a[l] == x ? l : -1;
      int p = l + (int)((long)(x - a[l]) * (r - l) / (a[r] - a[l]));
      if (a[p] == x)
        return p;
      if (a[p] < x)
        l = p + 1;
      else
        r = p - 1;
    }
    return -1;
  }
  public static void Main() {
    Console.WriteLine(Search(new[] { 1, 2, 2, 4 }, 2));
  }
}
