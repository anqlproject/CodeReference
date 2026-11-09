// Directed adjacency lists; returns no ordering when a directed cycle exists.
using System;
using System.Collections.Generic;
public static class TopologicalSort {
  public static int[] Run(int[][] g) {
    var d = new int[g.Length];
    foreach (var r in g)
      foreach (int v in r)
        d[v]++;
    var q = new Queue<int>();
    for (int i = 0; i < d.Length; i++)
      if (d[i] == 0)
        q.Enqueue(i);
    var o = new List<int>();
    while (q.Count > 0) {
      int u = q.Dequeue();
      o.Add(u);
      foreach (int v in g[u])
        if (--d[v] == 0)
          q.Enqueue(v);
    }
    return o.Count == g.Length ? o.ToArray() : null;
  }
  public static void Main() {
    Console.WriteLine(
        string.Join(" ", Run(new[] { new[] { 1, 2 }, new[] { 3 }, new[] { 3 },
                                     Array.Empty<int>() })));
  }
}
