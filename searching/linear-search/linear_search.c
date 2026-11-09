#include <stdio.h>
int linear_search(int *a, int n, int x) {
  for (int i = 0; i < n; i++)
    if (a[i] == x)
      return i;
  return -1;
}
int main(void) {
  int a[] = {4, 2, 7};
  printf("%d\n", linear_search(a, 3, 2));
}
