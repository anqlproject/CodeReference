#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void merge_sort_range(int *a, int *tmp, size_t lo, size_t hi) { if (hi - lo < 2) return; size_t mid = lo + (hi - lo) / 2; merge_sort_range(a, tmp, lo, mid); merge_sort_range(a, tmp, mid, hi); size_t i = lo, j = mid, k = lo; while (i < mid || j < hi) tmp[k++] = (j == hi || (i < mid && a[i] <= a[j])) ? a[i++] : a[j++]; memcpy(a + lo, tmp + lo, (hi - lo) * sizeof *a); }

void merge_sort(int *a, size_t n) {
    if (n < 2) return; int *tmp = malloc(n * sizeof *tmp); if (!tmp) return; merge_sort_range(a, tmp, 0, n); free(tmp);
}

int main(void) { int values[] = {5, 1, 4, 2, 8}; size_t n = sizeof values / sizeof values[0]; merge_sort(values, n); for (size_t i = 0; i < n; i++) printf("%s%d", i ? " " : "", values[i]); putchar('\n'); return 0; }
