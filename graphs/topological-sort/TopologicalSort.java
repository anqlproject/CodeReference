// Directed adjacency lists; returns no ordering when a directed cycle exists.
import java.util.*;
public class TopologicalSort {
  static List<Integer> run(int[][] g) {
    int[] d = new int[g.length];
    for (int[] r : g)
      for (int v : r)
        d[v]++;
    Queue<Integer> q = new ArrayDeque<>();
    for (int i = 0; i < d.length; i++)
      if (d[i] == 0)
        q.add(i);
    List<Integer> o = new ArrayList<>();
    while (!q.isEmpty()) {
      int u = q.remove();
      o.add(u);
      for (int v : g[u])
        if (--d[v] == 0)
          q.add(v);
    }
    return o.size() == g.length ? o : null;
  }
  public static void main(String[] z) {
    System.out.println(run(new int[][] {{1, 2}, {3}, {3}, {}}));
  }
}
