// Integer-indexed directed adjacency lists; visits only vertices reachable from
// start.
import java.util.*;
public class BreadthFirstSearch {
  static List<Integer> run(int[][] g, int s) {
    boolean[] seen = new boolean[g.length];
    List<Integer> q = new ArrayList<>(), o = new ArrayList<>();
    q.add(s);
    seen[s] = true;
    for (int i = 0; i < q.size(); i++) {
      int u = q.get(i);
      o.add(u);
      for (int v : g[u])
        if (!seen[v]) {
          seen[v] = true;
          q.add(v);
        }
    }
    return o;
  }
  public static void main(String[] z) {
    System.out.println(run(new int[][] {{1, 2}, {3}, {3}, {}}, 0));
  }
}
