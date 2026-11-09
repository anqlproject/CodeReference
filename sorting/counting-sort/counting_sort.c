#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void counting_sort(int *a, size_t n) {
    /* The integer range must be small enough for its count array to fit in memory. */
    if (!n) return; int min = a[0], max = a[0]; for (size_t i = 1; i < n; i++) { if (a[i] < min) min = a[i]; if (a[i] > max) max = a[i]; } size_t range = (size_t)((int64_t)max - min + 1); size_t *counts = calloc(range, sizeof *counts); if (!counts) return; for (size_t i = 0; i < n; i++) counts[(size_t)((int64_t)a[i] - min)]++; size_t k = 0; for (size_t i = 0; i < range; i++) while (counts[i]--) a[k++] = (int)((int64_t)min + i); free(counts);
}

int main(void) { int values[] = {5, 1, 4, 2, 8}; size_t n = sizeof values / sizeof values[0]; counting_sort(values, n); for (size_t i = 0; i < n; i++) printf("%s%d", i ? " " : "", values[i]); putchar('\n'); return 0; }
