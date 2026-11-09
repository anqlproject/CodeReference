import java.util.Arrays;
public final class HeapSort {
    public static int[] sort(int[] values) {
        int[] a = values.clone();
        for (int i = a.length / 2 - 1; i >= 0; i--) sift(a, i, a.length);
        for (int end = a.length - 1; end > 0; end--) { swap(a, 0, end); sift(a, 0, end); }
        return a;
    }
    private static void sift(int[] a, int root, int size) { while (2 * root + 1 < size) { int child = 2 * root + 1; if (child + 1 < size && a[child] < a[child + 1]) child++; if (a[root] >= a[child]) break; swap(a, root, child); root = child; } }
    private static void swap(int[] a, int i, int j) { int t = a[i]; a[i] = a[j]; a[j] = t; }
    public static void main(String[] args) { System.out.println(Arrays.toString(sort(new int[]{5, 1, 4, 2, 8}))); }
}
