#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void shell_sort(int *a, size_t n) {
  for (size_t gap = n / 2; gap > 0; gap /= 2)
    for (size_t i = gap; i < n; i++) {
      int v = a[i];
      size_t j = i;
      while (j >= gap && a[j - gap] > v) {
        a[j] = a[j - gap];
        j -= gap;
      }
      a[j] = v;
    }
}

int main(void) {
  int values[] = {5, 1, 4, 2, 8};
  size_t n = sizeof values / sizeof values[0];
  shell_sort(values, n);
  for (size_t i = 0; i < n; i++)
    printf("%s%d", i ? " " : "", values[i]);
  putchar('\n');
  return 0;
}
