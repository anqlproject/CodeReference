#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void selection_sort(int *a, size_t n) {
    for (size_t i = 0; i < n; i++) { size_t min = i; for (size_t j = i + 1; j < n; j++) if (a[j] < a[min]) min = j; int t = a[i]; a[i] = a[min]; a[min] = t; }
}

int main(void) { int values[] = {5, 1, 4, 2, 8}; size_t n = sizeof values / sizeof values[0]; selection_sort(values, n); for (size_t i = 0; i < n; i++) printf("%s%d", i ? " " : "", values[i]); putchar('\n'); return 0; }
