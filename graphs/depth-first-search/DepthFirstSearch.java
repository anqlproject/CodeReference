// Integer-indexed directed adjacency lists; visits only vertices reachable from
// start.
import java.util.*;
public class DepthFirstSearch {
  static List<Integer> run(int[][] g, int s) {
    boolean[] seen = new boolean[g.length];
    List<Integer> o = new ArrayList<>();
    Deque<Integer> st = new ArrayDeque<>();
    st.push(s);
    while (!st.isEmpty()) {
      int u = st.pop();
      if (seen[u])
        continue;
      seen[u] = true;
      o.add(u);
      for (int i = g[u].length - 1; i >= 0; i--)
        st.push(g[u][i]);
    }
    return o;
  }
  public static void main(String[] z) {
    System.out.println(run(new int[][] {{1, 2}, {3}, {3}, {}}, 0));
  }
}
