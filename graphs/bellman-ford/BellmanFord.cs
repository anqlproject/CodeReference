// Directed weighted edge list; negative weights are allowed; reachable negative
// cycles are reported.
using System;
public static class BellmanFord {
  public static long[] Run(int n, (int from, int to, int weight)[] e, int s) {
    var d = new long[n];
    Array.Fill(d, long.MaxValue);
    d[s] = 0;
    for (int i = 1; i < n; i++) {
      bool c = false;
      foreach (var x in e)
        if (d[x.from] != long.MaxValue && d[x.from] + x.weight < d[x.to]) {
          d[x.to] = d[x.from] + x.weight;
          c = true;
        }
      if (!c)
        break;
    }
    foreach (var x in e)
      if (d[x.from] != long.MaxValue && d[x.from] + x.weight < d[x.to])
        throw new ArgumentException("negative cycle");
    return d;
  }
  public static void Main() {
    Console.WriteLine(string.Join(
        " ", Run(3, new[] { (0, 1, 4), (0, 2, 5), (1, 2, -2) }, 0)));
  }
}
