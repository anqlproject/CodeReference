public class Fibonacci {
  static long run(int n) {
    if (n < 0)
      throw new IllegalArgumentException();
    long a = 0, b = 1;
    for (int i = 0; i < n; i++) {
      long t = a + b;
      a = b;
      b = t;
    }
    return a;
  }
  public static void main(String[] z) {
    System.out.println(run(10));
  }
}
