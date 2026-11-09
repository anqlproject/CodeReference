using System;
using System.Collections.Generic;
public static class SieveOfEratosthenes {
  public static List<int> Run(int n) {
    var o = new List<int>();
    if (n < 2)
      return o;
    var p = new bool[n + 1];
    Array.Fill(p, true);
    p[0] = p[1] = false;
    for (int i = 2; i * i <= n; i++)
      if (p[i])
        for (int j = i * i; j <= n; j += i)
          p[j] = false;
    for (int i = 2; i <= n; i++)
      if (p[i])
        o.Add(i);
    return o;
  }
  public static void Main() {
    Console.WriteLine(string.Join(" ", Run(30)));
  }
}
