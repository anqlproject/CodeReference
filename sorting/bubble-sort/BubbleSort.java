import java.util.Arrays;
public final class BubbleSort {
    public static int[] sort(int[] values) {
        int[] a = values.clone();
        for (int end = a.length - 1; end > 0; end--) {
            boolean swapped = false;
            for (int i = 0; i < end; i++) if (a[i] > a[i + 1]) { int t = a[i]; a[i] = a[i + 1]; a[i + 1] = t; swapped = true; }
            if (!swapped) break;
        }
        return a;
    }
    public static void main(String[] args) { System.out.println(Arrays.toString(sort(new int[]{5, 1, 4, 2, 8}))); }
}
