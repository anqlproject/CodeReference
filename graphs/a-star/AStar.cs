// Weighted adjacency lists require nonnegative weights; admissible heuristic
// estimates remaining cost.
using System;
using System.Collections.Generic;
public static class AStar {
  public static int Run((int to, int weight)[][] g, int s, int goal,
                        Func<int, int> h) {
    var d = new int[g.Length];
    Array.Fill(d, int.MaxValue);
    d[s] = 0;
    var q = new PriorityQueue<int, int>();
    q.Enqueue(s, h(s));
    while (q.TryDequeue(out int u, out _)) {
      if (u == goal)
        return d[u];
      foreach (var e in g[u]) {
        if (e.weight < 0)
          throw new ArgumentException("negative edge");
        if (d[u] + e.weight < d[e.to]) {
          d[e.to] = d[u] + e.weight;
          q.Enqueue(e.to, d[e.to] + h(e.to));
        }
      }
    }
    return -1;
  }
  public static void Main() {
    Console.WriteLine(Run(new[] { new[] { (1, 2), (2, 5) }, new[] { (2, 1) },
                                  Array.Empty<(int, int)>() },
                          0, 2,
                          _ => 0));
  }
}
