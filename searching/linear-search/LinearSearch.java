import java.util.*;
public class LinearSearch {
  static int search(int[] a, int x) {
    for (int i = 0; i < a.length; i++)
      if (a[i] == x)
        return i;
    return -1;
  }
  public static void main(String[] z) {
    System.out.println(search(new int[] {4, 2, 7}, 2));
  }
}
