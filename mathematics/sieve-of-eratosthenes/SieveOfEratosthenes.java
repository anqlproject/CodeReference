import java.util.*;
public class SieveOfEratosthenes {
  static List<Integer> run(int n) {
    List<Integer> o = new ArrayList<>();
    if (n < 2)
      return o;
    boolean[] p = new boolean[n + 1];
    Arrays.fill(p, true);
    p[0] = p[1] = false;
    for (int i = 2; i * i <= n; i++)
      if (p[i])
        for (int j = i * i; j <= n; j += i)
          p[j] = false;
    for (int i = 2; i <= n; i++)
      if (p[i])
        o.add(i);
    return o;
  }
  public static void main(String[] z) {
    System.out.println(run(30));
  }
}
