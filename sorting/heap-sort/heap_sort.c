#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void sift(int *a, size_t root, size_t size) {
  while (root * 2 + 1 < size) {
    size_t child = root * 2 + 1;
    if (child + 1 < size && a[child] < a[child + 1])
      child++;
    if (a[root] >= a[child])
      break;
    int t = a[root];
    a[root] = a[child];
    a[child] = t;
    root = child;
  }
}

void heap_sort(int *a, size_t n) {
  for (size_t i = n / 2; i > 0; i--)
    sift(a, i - 1, n);
  for (size_t end = n; end > 1; end--) {
    int t = a[0];
    a[0] = a[end - 1];
    a[end - 1] = t;
    sift(a, 0, end - 1);
  }
}

int main(void) {
  int values[] = {5, 1, 4, 2, 8};
  size_t n = sizeof values / sizeof values[0];
  heap_sort(values, n);
  for (size_t i = 0; i < n; i++)
    printf("%s%d", i ? " " : "", values[i]);
  putchar('\n');
  return 0;
}
