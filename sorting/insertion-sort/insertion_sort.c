#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void insertion_sort(int *a, size_t n) {
  for (size_t i = 1; i < n; i++) {
    int v = a[i];
    size_t j = i;
    while (j > 0 && a[j - 1] > v) {
      a[j] = a[j - 1];
      j--;
    }
    a[j] = v;
  }
}

int main(void) {
  int values[] = {5, 1, 4, 2, 8};
  size_t n = sizeof values / sizeof values[0];
  insertion_sort(values, n);
  for (size_t i = 0; i < n; i++)
    printf("%s%d", i ? " " : "", values[i]);
  putchar('\n');
  return 0;
}
