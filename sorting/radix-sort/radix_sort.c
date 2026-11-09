#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void radix_sort(int *a, size_t n) {
    /* Values must be non-negative. */
    for (size_t i = 0; i < n; i++) if (a[i] < 0) return; int max = 0; for (size_t i = 0; i < n; i++) if (a[i] > max) max = a[i]; int *out = malloc(n * sizeof *out); if (!out) return; for (int64_t exp = 1; max / exp > 0; exp *= 10) { size_t count[10] = {0}; for (size_t i = 0; i < n; i++) count[(a[i] / exp) % 10]++; for (size_t i = 1; i < 10; i++) count[i] += count[i - 1]; for (size_t i = n; i > 0; i--) { size_t d = (size_t)((a[i - 1] / exp) % 10); out[--count[d]] = a[i - 1]; } memcpy(a, out, n * sizeof *a); } free(out);
}

int main(void) { int values[] = {5, 1, 4, 2, 8}; size_t n = sizeof values / sizeof values[0]; radix_sort(values, n); for (size_t i = 0; i < n; i++) printf("%s%d", i ? " " : "", values[i]); putchar('\n'); return 0; }
