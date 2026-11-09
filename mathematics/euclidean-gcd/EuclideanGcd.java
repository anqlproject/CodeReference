public class EuclideanGcd {
  static long run(long a, long b) {
    a = Math.abs(a);
    b = Math.abs(b);
    while (b != 0) {
      long t = a % b;
      a = b;
      b = t;
    }
    return a;
  }
  public static void main(String[] z) {
    System.out.println(run(48, 18));
  }
}
