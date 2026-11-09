import java.util.Arrays;
public final class CountingSort {
  public static int[] sort(int[] values) {
    // The integer range must be small enough for its count array to fit in
    // memory.
    if (values.length == 0)
      return new int[0];
    int min = values[0], max = values[0];
    for (int v : values) {
      min = Math.min(min, v);
      max = Math.max(max, v);
    }
    long rangeLong = (long)max - min + 1;
    if (rangeLong > Integer.MAX_VALUE)
      throw new IllegalArgumentException("integer range is too large");
    int[] counts = new int[(int)rangeLong];
    for (int v : values)
      counts[(int)((long)v - min)]++;
    int[] result = new int[values.length];
    int k = 0;
    for (int i = 0; i < counts.length; i++)
      while (counts[i]-- > 0)
        result[k++] = (int)((long)min + i);
    return result;
  }
  public static void main(String[] args) {
    System.out.println(Arrays.toString(sort(new int[] {5, 1, 4, 2, 8})));
  }
}
