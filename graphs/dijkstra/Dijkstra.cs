// Weighted adjacency lists; edge weights must be nonnegative.
using System;
using System.Collections.Generic;
public static class Dijkstra {
  public static long[] Run((int to, int weight)[][] g, int s) {
    var d = new long[g.Length];
    Array.Fill(d, long.MaxValue);
    d[s] = 0;
    var q = new PriorityQueue<int, long>();
    q.Enqueue(s, 0);
    while (q.TryDequeue(out int u, out long du)) {
      if (du != d[u])
        continue;
      foreach (var e in g[u]) {
        if (e.weight < 0)
          throw new ArgumentException("negative edge");
        if (du + e.weight < d[e.to]) {
          d[e.to] = du + e.weight;
          q.Enqueue(e.to, d[e.to]);
        }
      }
    }
    return d;
  }
  public static void Main() {
    Console.WriteLine(
        string.Join(" ", Run(new[] { new[] { (1, 2), (2, 5) }, new[] { (2, 1) },
                                     Array.Empty<(int, int)>() },
                             0)));
  }
}
