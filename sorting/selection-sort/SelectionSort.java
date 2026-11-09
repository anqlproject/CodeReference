import java.util.Arrays;
public final class SelectionSort {
    public static int[] sort(int[] values) {
        int[] a = values.clone();
        for (int i = 0; i < a.length; i++) { int min = i; for (int j = i + 1; j < a.length; j++) if (a[j] < a[min]) min = j; int t = a[i]; a[i] = a[min]; a[min] = t; }
        return a;
    }
    public static void main(String[] args) { System.out.println(Arrays.toString(sort(new int[]{5, 1, 4, 2, 8}))); }
}
