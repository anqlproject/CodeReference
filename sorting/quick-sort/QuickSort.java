import java.util.Arrays;
public final class QuickSort {
  public static int[] sort(int[] values) {
    int[] a = values.clone();
    if (a.length > 0)
      quickSort(a, 0, a.length - 1);
    return a;
  }
  private static void quickSort(int[] a, int lo, int hi) {
    int i = lo, j = hi, pivot = a[lo + (hi - lo) / 2];
    while (i <= j) {
      while (a[i] < pivot)
        i++;
      while (a[j] > pivot)
        j--;
      if (i <= j) {
        swap(a, i++, j--);
      }
    }
    if (lo < j)
      quickSort(a, lo, j);
    if (i < hi)
      quickSort(a, i, hi);
  }
  public static void main(String[] args) {
    System.out.println(Arrays.toString(sort(new int[] {5, 1, 4, 2, 8})));
  }
}
