using System;
using System.Linq;
public static class CountingSort {
    public static int[] Sort(int[] values) {
        // The integer range must be small enough for its count array to fit in memory.
        if (values.Length == 0) return Array.Empty<int>(); int min = values.Min(), max = values.Max(); long range = (long)max - min + 1; if (range > int.MaxValue) throw new ArgumentException("integer range is too large"); int[] count = new int[(int)range]; foreach (int v in values) count[(int)((long)v - min)]++; int[] result = new int[values.Length]; int k = 0; for (int i = 0; i < count.Length; i++) while (count[i]-- > 0) result[k++] = (int)((long)min + i); return result;
    }
    public static void Main() { Console.WriteLine(string.Join(" ", Sort(new[] { 5, 1, 4, 2, 8 }))); }
}
