// Undirected weighted edge list; returns failure when the graph is
// disconnected.
import java.util.*;
public class Kruskal {
  static int f(int[] p, int x) {
    return p[x] == x ? x : (p[x] = f(p, p[x]));
  }
  static long run(int n, int[][] e) {
    for (int i = 1; i < e.length; i++) {
      int[] x = e[i];
      int j = i;
      while (j > 0 && e[j - 1][2] > x[2]) {
        e[j] = e[j - 1];
        j--;
      }
      e[j] = x;
    }
    int[] p = new int[n];
    for (int i = 0; i < n; i++)
      p[i] = i;
    long sum = 0;
    int k = 0;
    for (int[] x : e) {
      int a = f(p, x[0]), b = f(p, x[1]);
      if (a != b) {
        p[a] = b;
        sum += x[2];
        k++;
      }
    }
    return k == Math.max(0, n - 1) ? sum : Long.MIN_VALUE;
  }
  public static void main(String[] z) {
    System.out.println(run(3, new int[][] {{0, 1, 4}, {1, 2, 2}, {0, 2, 5}}));
  }
}
