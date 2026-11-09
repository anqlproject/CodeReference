using System;
public static class LinearSearch {
  public static int Search(int[] a, int x) {
    for (int i = 0; i < a.Length; i++)
      if (a[i] == x)
        return i;
    return -1;
  }
  public static void Main() {
    Console.WriteLine(Search(new[] { 4, 2, 7 }, 2));
  }
}
