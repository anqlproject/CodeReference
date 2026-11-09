// Integer-indexed directed adjacency lists; visits only vertices reachable from
// start.
using System;
using System.Collections.Generic;
public static class DepthFirstSearch {
  public static List<int> Run(int[][] g, int s) {
    var seen = new bool[g.Length];
    var o = new List<int>();
    var st = new Stack<int>();
    st.Push(s);
    while (st.Count > 0) {
      int u = st.Pop();
      if (seen[u])
        continue;
      seen[u] = true;
      o.Add(u);
      for (int i = g[u].Length - 1; i >= 0; i--)
        st.Push(g[u][i]);
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
