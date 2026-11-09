// Returns the length of a longest common subsequence.
using System;
public static class LongestCommonSubsequence {
  public static int Run(string a, string b) {
    var d = new int[b.Length + 1];
    foreach (char x in a) {
      int p = 0;
      for (int j = 1; j <= b.Length; j++) {
        int old = d[j];
        d[j] = x == b[j - 1] ? p + 1 : Math.Max(d[j], d[j - 1]);
        p = old;
      }
    }
    return d[b.Length];
  }
  public static void Main() {
    Console.WriteLine(Run("ABCBDAB", "BDCAB"));
  }
}
