#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void quick_sort_range(int *a, long lo, long hi) {
  long i = lo, j = hi;
  int pivot = a[lo + (hi - lo) / 2];
  while (i <= j) {
    while (a[i] < pivot)
      i++;
    while (a[j] > pivot)
      j--;
    if (i <= j) {
      int t = a[i];
      a[i++] = a[j];
      a[j--] = t;
    }
  }
  if (lo < j)
    quick_sort_range(a, lo, j);
  if (i < hi)
    quick_sort_range(a, i, hi);
}

void quick_sort(int *a, size_t n) {
  if (n > 1)
    quick_sort_range(a, 0, (long)n - 1);
}

int main(void) {
  int values[] = {5, 1, 4, 2, 8};
  size_t n = sizeof values / sizeof values[0];
  quick_sort(values, n);
  for (size_t i = 0; i < n; i++)
    printf("%s%d", i ? " " : "", values[i]);
  putchar('\n');
  return 0;
}
