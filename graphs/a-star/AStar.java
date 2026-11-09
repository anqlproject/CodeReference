// Weighted adjacency lists require nonnegative weights; admissible heuristic
// estimates remaining cost.
import java.util.*;
import java.util.function.ToIntFunction;
public class AStar {
  static int run(int[][][] g, int s, int goal, ToIntFunction<Integer> h) {
    int[] d = new int[g.length];
    Arrays.fill(d, Integer.MAX_VALUE);
    d[s] = 0;
    PriorityQueue<int[]> q =
        new PriorityQueue<>(Comparator.comparingInt(a -> a[0]));
    q.add(new int[] {h.applyAsInt(s), 0, s});
    while (!q.isEmpty()) {
      int[] x = q.poll();
      int u = x[2];
      if (x[1] != d[u])
        continue;
      if (u == goal)
        return d[u];
      for (int[] e : g[u]) {
        if (e[1] < 0)
          throw new IllegalArgumentException("negative edge");
        if (d[u] + e[1] < d[e[0]]) {
          d[e[0]] = d[u] + e[1];
          q.add(new int[] {d[e[0]] + h.applyAsInt(e[0]), d[e[0]], e[0]});
        }
      }
    }
    return -1;
  }
  public static void main(String[] z) {
    System.out.println(
        run(new int[][][] {{{1, 2}, {2, 5}}, {{2, 1}}, {}}, 0, 2, n -> 0));
  }
}
