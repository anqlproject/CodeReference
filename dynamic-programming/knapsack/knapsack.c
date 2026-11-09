// 0/1 knapsack contract: weights and capacity are nonnegative; returns maximum
// value.
#include <stdio.h>
int knapsack(int *w, int *v, int n, int c) {
  int d[c + 1];
  for (int j = 0; j <= c; j++)
    d[j] = 0;
  for (int i = 0; i < n; i++)
    for (int j = c; j >= w[i]; j--)
      if (d[j - w[i]] + v[i] > d[j])
        d[j] = d[j - w[i]] + v[i];
  return d[c];
}
int main(void) {
  int w[] = {2, 3, 4}, v[] = {4, 5, 6};
  printf("%d\n", knapsack(w, v, 3, 5));
}
