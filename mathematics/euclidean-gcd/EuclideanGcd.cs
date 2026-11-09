using System;
public static class EuclideanGcd {
  public static long Run(long a, long b) {
    a = Math.Abs(a);
    b = Math.Abs(b);
    while (b != 0) {
      long t = a % b;
      a = b;
      b = t;
    }
    return a;
  }
  public static void Main() {
    Console.WriteLine(Run(48, 18));
  }
}
