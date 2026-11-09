using System;
using System.Collections.Generic;
using System.Linq;
public static class BucketSort {
  public static int[] Sort(int[] values) {
    int[] result = (int[])values.Clone();
    if (result.Length < 2)
      return result;
    int min = result.Min(), max = result.Max();
    if (min == max)
      return result;
    var buckets = new List<int>[result.Length];
    for (int i = 0; i < buckets.Length; i++)
      buckets[i] = new List<int>();
    long span = (long)max - min + 1;
    foreach (int v in result) {
      int b = (int)Math.Min(((long)v - min) * result.Length / span,
                            result.Length - 1);
      buckets[b].Add(v);
    }
    int k = 0;
    foreach (var bucket in buckets) {
      for (int i = 1; i < bucket.Count; i++) {
        int v = bucket[i], j = i - 1;
        while (j >= 0 && bucket[j] > v) {
          bucket[j + 1] = bucket[j];
          j--;
        }
        bucket[j + 1] = v;
      }
      foreach (int v in bucket)
        result[k++] = v;
    }
    return result;
  }
  public static void Main() {
    Console.WriteLine(string.Join(" ", Sort(new[] { 5, 1, 4, 2, 8 })));
  }
}
