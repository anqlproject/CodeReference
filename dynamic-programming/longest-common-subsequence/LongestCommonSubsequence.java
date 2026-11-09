// Returns the length of a longest common subsequence.
public class LongestCommonSubsequence {
  static int run(String a, String b) {
    int[] d = new int[b.length() + 1];
    for (char x : a.toCharArray()) {
      int p = 0;
      for (int j = 1; j <= b.length(); j++) {
        int old = d[j];
        d[j] = x == b.charAt(j - 1) ? p + 1 : Math.max(d[j], d[j - 1]);
        p = old;
      }
    }
    return d[b.length()];
  }
  public static void main(String[] z) {
    System.out.println(run("ABCBDAB", "BDCAB"));
  }
}
