// Input is sorted ascending; when duplicates occur, any matching index may be
// returned.
#include <stdio.h>
int interpolation_search(int *a, int n, int x) {
  int l = 0, r = n - 1;
  while (l <= r && a[l] <= x && x <= a[r]) {
    if (a[l] == a[r])
      return a[l] == x ? l : -1;
    int p = l + (long long)(x - a[l]) * (r - l) / (a[r] - a[l]);
    if (a[p] == x)
      return p;
    if (a[p] < x)
      l = p + 1;
    else
      r = p - 1;
  }
  return -1;
}
int main(void) {
  int a[] = {1, 2, 2, 4};
  printf("%d\n", interpolation_search(a, 4, 2));
}
