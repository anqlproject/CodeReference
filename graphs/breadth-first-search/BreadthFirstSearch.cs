// Integer-indexed directed adjacency lists; visits only vertices reachable from
// start.
using System;
using System.Collections.Generic;
public static class BreadthFirstSearch {
  public static List<int> Run(int[][] g, int s) {
    var seen = new bool[g.Length];
    var q = new List<int> { s };
    var o = new List<int>();
    seen[s] = true;
    for (int i = 0; i < q.Count; i++) {
      int u = q[i];
      o.Add(u);
      foreach (int v in g[u])
        if (!seen[v]) {
          seen[v] = true;
          q.Add(v);
        }
    }
    return o;
  }
  public static void Main() {
    Console.WriteLine(
        string.Join(" ", Run(new[] { new[] { 1, 2 }, new[] { 3 }, new[] { 3 },
                                     Array.Empty<int>() },
                             0)));
  }
}
