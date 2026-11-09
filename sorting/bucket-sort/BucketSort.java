import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
public final class BucketSort {
  public static int[] sort(int[] values) {
    int[] result = values.clone();
    if (result.length < 2)
      return result;
    int min = result[0], max = result[0];
    for (int v : result) {
      min = Math.min(min, v);
      max = Math.max(max, v);
    }
    if (min == max)
      return result;
    List<List<Integer>> buckets = new ArrayList<>();
    for (int i = 0; i < result.length; i++)
      buckets.add(new ArrayList<>());
    long span = (long)max - min + 1;
    for (int v : result) {
      int b = (int)Math.min(((long)v - min) * result.length / span,
                            result.length - 1);
      buckets.get(b).add(v);
    }
    int k = 0;
    for (List<Integer> bucket : buckets) {
      for (int i = 1; i < bucket.size(); i++) {
        int v = bucket.get(i), j = i - 1;
        while (j >= 0 && bucket.get(j) > v) {
          bucket.set(j + 1, bucket.get(j));
          j--;
        }
        bucket.set(j + 1, v);
      }
      for (int v : bucket)
        result[k++] = v;
    }
    return result;
  }
  public static void main(String[] args) {
    System.out.println(Arrays.toString(sort(new int[] {5, 1, 4, 2, 8})));
  }
}
