// Undirected weighted adjacency lists; returns failure when the graph is
// disconnected.
using System;
public static class Prim {
  public static long Run((int to, int w)[][] g) {
    if (g.Length == 0)
      return 0;
    var s = new bool[g.Length];
    s[0] = true;
    int n = 1;
    long sum = 0;
    while (n < g.Length) {
      int v = -1, bw = int.MaxValue;
      for (int u = 0; u < g.Length; u++)
        if (s[u])
          foreach (var e in g[u])
            if (!s[e.to] && e.w < bw) {
              v = e.to;
              bw = e.w;
            }
      if (v < 0)
        return -1;
      s[v] = true;
      n++;
      sum += bw;
    }
    return sum;
  }
  public static void Main() {
    Console.WriteLine(
        Run(new[] { new[] { (1, 4), (2, 5) }, new[] { (0, 4), (2, 2) },
                    new[] { (0, 5), (1, 2) } }));
  }
}
