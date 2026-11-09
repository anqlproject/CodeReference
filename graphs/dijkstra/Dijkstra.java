// Weighted adjacency lists; edge weights must be nonnegative.
import java.util.*;
public class Dijkstra {
  static long[] run(int[][][] g, int s) {
    long[] d = new long[g.length];
    Arrays.fill(d, Long.MAX_VALUE);
    d[s] = 0;
    PriorityQueue<long[]> q =
        new PriorityQueue<>(Comparator.comparingLong(a -> a[0]));
    q.add(new long[] {0, s});
    while (!q.isEmpty()) {
      long[] x = q.poll();
      int u = (int)x[1];
      if (x[0] != d[u])
        continue;
      for (int[] e : g[u]) {
        if (e[1] < 0)
          throw new IllegalArgumentException("negative edge");
        if (d[u] + e[1] < d[e[0]]) {
          d[e[0]] = d[u] + e[1];
          q.add(new long[] {d[e[0]], e[0]});
        }
      }
    }
    return d;
  }
  public static void main(String[] z) {
    System.out.println(Arrays.toString(
        run(new int[][][] {{{1, 2}, {2, 5}}, {{2, 1}}, {}}, 0)));
  }
}
