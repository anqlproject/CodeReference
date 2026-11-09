// Directed weighted edge list; negative weights are allowed; reachable negative
// cycles are reported.
import java.util.*;
public class BellmanFord {
  static long[] run(int n, int[][] e, int s) {
    long[] d = new long[n];
    Arrays.fill(d, Long.MAX_VALUE);
    d[s] = 0;
    for (int i = 1; i < n; i++) {
      boolean c = false;
      for (int[] x : e)
        if (d[x[0]] != Long.MAX_VALUE && d[x[0]] + x[2] < d[x[1]]) {
          d[x[1]] = d[x[0]] + x[2];
          c = true;
        }
      if (!c)
        break;
    }
    for (int[] x : e)
      if (d[x[0]] != Long.MAX_VALUE && d[x[0]] + x[2] < d[x[1]])
        throw new IllegalArgumentException("negative cycle");
    return d;
  }
  public static void main(String[] z) {
    System.out.println(Arrays.toString(
        run(3, new int[][] {{0, 1, 4}, {0, 2, 5}, {1, 2, -2}}, 0)));
  }
}
