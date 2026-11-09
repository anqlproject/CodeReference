import java.util.Arrays;
public final class MergeSort {
  public static int[] sort(int[] values) {
    int[] a = values.clone();
    mergeSort(a, new int[a.length], 0, a.length);
    return a;
  }
  private static void mergeSort(int[] a, int[] temp, int lo, int hi) {
    if (hi - lo < 2)
      return;
    int mid = (lo + hi) / 2;
    mergeSort(a, temp, lo, mid);
    mergeSort(a, temp, mid, hi);
    int i = lo, j = mid, k = lo;
    while (i < mid || j < hi)
      temp[k++] = (j == hi || (i < mid && a[i] <= a[j])) ? a[i++] : a[j++];
    System.arraycopy(temp, lo, a, lo, hi - lo);
  }
  public static void main(String[] args) {
    System.out.println(Arrays.toString(sort(new int[] {5, 1, 4, 2, 8})));
  }
}
