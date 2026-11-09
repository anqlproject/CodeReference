// Weighted adjacency lists require nonnegative weights; admissible heuristic
// estimates remaining cost.
#include <limits.h>
#include <stdio.h>
typedef struct {
  int v, w;
} E;
int astar(E g[3][2], int deg[3], int s, int goal, int (*h)(int)) {
  int d[3] = {INT_MAX, INT_MAX, INT_MAX}, used[3] = {0};
  d[s] = 0;
  for (int k = 0; k < 3; k++) {
    int u = -1;
    for (int i = 0; i < 3; i++)
      if (!used[i] && d[i] != INT_MAX && (u < 0 || d[i] + h(i) < d[u] + h(u)))
        u = i;
    if (u < 0)
      return -1;
    if (u == goal)
      return d[u];
    used[u] = 1;
    for (int j = 0; j < deg[u]; j++) {
      E e = g[u][j];
      if (e.w < 0)
        return -1;
      if (d[u] + e.w < d[e.v])
        d[e.v] = d[u] + e.w;
    }
  }
  return -1;
}
int zero(int x) {
  (void)x;
  return 0;
}
int main(void) {
  E g[3][2] = {{{1, 2}, {2, 5}}, {{2, 1}}, {{0, 0}}};
  int d[] = {2, 1, 0};
  printf("%d\n", astar(g, d, 0, 2, zero));
}
