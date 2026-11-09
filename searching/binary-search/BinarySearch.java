import java.util.*;
public class BinarySearch {
  static int search(int[] a, int x) {
    int l = 0, r = a.length - 1;
    while (l <= r) {
      int m = l + (r - l) / 2;
      if (a[m] == x)
        return m;
      if (a[m] < x)
        l = m + 1;
      else
        r = m - 1;
    }
    return -1;
  }
  public static void main(String[] z) {
    System.out.println(search(new int[] {1, 3, 5, 7}, 5));
  }
}
