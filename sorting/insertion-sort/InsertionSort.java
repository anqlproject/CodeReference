import java.util.Arrays;
public final class InsertionSort {
    public static int[] sort(int[] values) {
        int[] a = values.clone();
        for (int i = 1; i < a.length; i++) { int value = a[i], j = i - 1; while (j >= 0 && a[j] > value) { a[j + 1] = a[j]; j--; } a[j + 1] = value; }
        return a;
    }
    public static void main(String[] args) { System.out.println(Arrays.toString(sort(new int[]{5, 1, 4, 2, 8}))); }
}
