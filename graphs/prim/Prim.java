// Undirected weighted adjacency lists; returns failure when the graph is
// disconnected.
import java.util.*;
public class Prim {
  static long run(int[][][] g) {
    if (g.length == 0)
      return 0;
    boolean[] s = new boolean[g.length];
    s[0] = true;
    int n = 1;
    long sum = 0;
    while (n < g.length) {
      int bu = -1, bv = -1, bw = Integer.MAX_VALUE;
      for (int u = 0; u < g.length; u++)
        if (s[u])
          for (int[] e : g[u])
            if (!s[e[0]] && e[1] < bw) {
              bu = u;
              bv = e[0];
              bw = e[1];
            }
      if (bv < 0)
        return Long.MIN_VALUE;
      s[bv] = true;
      n++;
      sum += bw;
    }
    return sum;
  }
  public static void main(String[] z) {
    System.out.println(run(
        new int[][][] {{{1, 4}, {2, 5}}, {{0, 4}, {2, 2}}, {{0, 5}, {1, 2}}}));
  }
}
