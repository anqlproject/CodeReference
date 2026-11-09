#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void bubble_sort(int *a, size_t n) {
    for (size_t end = n; end > 1; end--) { int swapped = 0; for (size_t i = 0; i + 1 < end; i++) if (a[i] > a[i + 1]) { int t = a[i]; a[i] = a[i + 1]; a[i + 1] = t; swapped = 1; } if (!swapped) break; }
}

int main(void) { int values[] = {5, 1, 4, 2, 8}; size_t n = sizeof values / sizeof values[0]; bubble_sort(values, n); for (size_t i = 0; i < n; i++) printf("%s%d", i ? " " : "", values[i]); putchar('\n'); return 0; }
