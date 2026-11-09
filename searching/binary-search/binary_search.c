#include <stdio.h>
int binary_search(int *a, int n, int x) {
  int l = 0, r = n - 1;
  while (l <= r) {
    int m = l + (r - l) / 2;
    if (a[m] == x)
      return m;
    if (a[m] < x)
      l = m + 1;
    else
      r = m - 1;
  }
  return -1;
}
int main(void) {
  int a[] = {1, 3, 5, 7};
  printf("%d\n", binary_search(a, 4, 5));
}
