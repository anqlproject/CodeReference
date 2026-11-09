// Input is sorted ascending; when duplicates occur, any matching index may be
// returned.
public class InterpolationSearch {
  static int search(int[] a, int x) {
    int l = 0, r = a.length - 1;
    while (l <= r && a[l] <= x && x <= a[r]) {
      if (a[l] == a[r])
        return a[l] == x ? l : -1;
      int p = l + (int)((long)(x - a[l]) * (r - l) / (a[r] - a[l]));
      if (a[p] == x)
        return p;
      if (a[p] < x)
        l = p + 1;
      else
        r = p - 1;
    }
    return -1;
  }
  public static void main(String[] z) {
    System.out.println(search(new int[] {1, 2, 2, 4}, 2));
  }
}
