// 0/1 knapsack contract: weights and capacity are nonnegative; returns maximum
// value.
using System;
public static class Knapsack {
  public static int Run(int[] w, int[] v, int c) {
    if (c < 0)
      throw new ArgumentException();
    var d = new int[c + 1];
    for (int i = 0; i < w.Length; i++) {
      if (w[i] < 0)
        throw new ArgumentException();
      for (int j = c; j >= w[i]; j--)
        d[j] = Math.Max(d[j], d[j - w[i]] + v[i]);
    }
    return d[c];
  }
  public static void Main() {
    Console.WriteLine(Run(new[] { 2, 3, 4 }, new[] { 4, 5, 6 }, 5));
  }
}
