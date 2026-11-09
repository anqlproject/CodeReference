import java.util.Arrays;
public final class RadixSort {
  public static int[] sort(int[] values) {
    int[] a = values.clone();
    for (int v : a)
      if (v < 0)
        throw new IllegalArgumentException(
            "radix sort supports non-negative integers only");
    int max = 0;
    for (int v : a)
      max = Math.max(max, v);
    int[] output = new int[a.length];
    for (long exp = 1; max / exp > 0; exp *= 10) {
      int[] count = new int[10];
      for (int v : a)
        count[(int)((v / exp) % 10)]++;
      for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];
      for (int i = a.length - 1; i >= 0; i--) {
        int digit = (int)((a[i] / exp) % 10);
        output[--count[digit]] = a[i];
      }
      int[] temp = a;
      a = output;
      output = temp;
    }
    return a;
  }
  public static void main(String[] args) {
    System.out.println(Arrays.toString(sort(new int[] {5, 1, 4, 2, 8})));
  }
}
