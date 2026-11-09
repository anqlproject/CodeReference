using System;
public static class FastExponentiation {
  public static double Run(double b, int e) {
    if (e < 0)
      return 1 / Run(b, -e);
    double r = 1;
    while (e > 0) {
      if ((e & 1) != 0)
        r *= b;
      b *= b;
      e >>= 1;
    }
    return r;
  }
  public static void Main() {
    Console.WriteLine(Run(2, 10));
  }
}
