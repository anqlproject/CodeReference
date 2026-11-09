import java.util.Arrays;
public final class ShellSort {
    public static int[] sort(int[] values) {
        int[] a = values.clone();
        for (int gap = a.length / 2; gap > 0; gap /= 2) for (int i = gap; i < a.length; i++) { int v = a[i], j = i; while (j >= gap && a[j - gap] > v) { a[j] = a[j - gap]; j -= gap; } a[j] = v; }
        return a;
    }
    public static void main(String[] args) { System.out.println(Arrays.toString(sort(new int[]{5, 1, 4, 2, 8}))); }
}
