using System;
public static class Fibonacci {
  public static long Run(int n) {
    if (n < 0)
      throw new ArgumentException();
    long a = 0, b = 1;
    for (int i = 0; i < n; i++) {
      long t = a + b;
      a = b;
      b = t;
    }
    return a;
  }
  public static void Main() {
    Console.WriteLine(Run(10));
  }
}
