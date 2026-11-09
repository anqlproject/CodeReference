// 0/1 knapsack contract: weights and capacity are nonnegative; returns maximum
// value.
public class Knapsack {
  static int run(int[] w, int[] v, int c) {
    if (c < 0)
      throw new IllegalArgumentException();
    int[] d = new int[c + 1];
    for (int i = 0; i < w.length; i++) {
      if (w[i] < 0)
        throw new IllegalArgumentException();
      for (int j = c; j >= w[i]; j--)
        d[j] = Math.max(d[j], d[j - w[i]] + v[i]);
    }
    return d[c];
  }
  public static void main(String[] z) {
    System.out.println(run(new int[] {2, 3, 4}, new int[] {4, 5, 6}, 5));
  }
}
