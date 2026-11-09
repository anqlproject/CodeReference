public class FastExponentiation {
  static double run(double b, int e) {
    if (e < 0)
      return 1 / run(b, -e);
    double r = 1;
    while (e > 0) {
      if ((e & 1) != 0)
        r *= b;
      b *= b;
      e >>= 1;
    }
    return r;
  }
  public static void main(String[] z) {
    System.out.println(run(2, 10));
  }
}
