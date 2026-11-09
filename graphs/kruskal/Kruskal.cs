// Undirected weighted edge list; returns failure when the graph is
// disconnected.
using System;
using System.Linq;
public static class Kruskal {
  static int Find(int[] p, int x) => p[x] == x ? x : (p[x] = Find(p, p[x]));
  public static long Run(int n, (int u, int v, int w)[] e) {
    var p = Enumerable.Range(0, n).ToArray();
    long sum = 0;
    int k = 0;
    var ordered = (ValueTuple<int, int, int>[])e.Clone();
    for (int i = 1; i < ordered.Length; i++) {
      var x = ordered[i];
      int j = i;
      while (j > 0 && ordered[j - 1].Item3 > x.Item3) {
        ordered[j] = ordered[j - 1];
        j--;
      }
      ordered[j] = x;
    }
    foreach (var x in ordered) {
      int a = Find(p, x.u), b = Find(p, x.v);
      if (a != b) {
        p[a] = b;
        sum += x.w;
        k++;
      }
    }
    return k == Math.Max(0, n - 1) ? sum : -1;
  }
  public static void Main() {
    Console.WriteLine(Run(3, new[] { (0, 1, 4), (1, 2, 2), (0, 2, 5) }));
  }
}
