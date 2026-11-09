// Weighted adjacency lists; edge weights must be nonnegative.
#include <limits.h>
#include <stdio.h>
typedef struct {
  int v, w;
} E;
int main(void) { /* weighted adjacency lists */
  E g[3][2] = {{{1, 2}, {2, 5}}, {{2, 1}}, {{0, 0}}};
  int deg[] = {2, 1, 0}, d[] = {INT_MAX, INT_MAX, INT_MAX}, used[3] = {0};
  d[0] = 0;
  for (int k = 0; k < 3; k++) {
    int u = -1;
    for (int i = 0; i < 3; i++)
      if (!used[i] && (u < 0 || d[i] < d[u]))
        u = i;
    if (u < 0 || d[u] == INT_MAX)
      break;
    used[u] = 1;
    for (int j = 0; j < deg[u]; j++) {
      E e = g[u][j];
      if (e.w < 0)
        return 1;
      if (d[u] + e.w < d[e.v])
        d[e.v] = d[u] + e.w;
    }
  }
  for (int i = 0; i < 3; i++)
    printf("%d ", d[i]);
}
