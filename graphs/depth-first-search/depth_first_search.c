// Integer-indexed directed adjacency lists; visits only vertices reachable from
// start.
#include <stdio.h>
#define N 4
int main(void) { /* adjacency lists; iterative DFS */
  int g[N][4] = {{2, 1, 2}, {1, 3}, {1, 3}, {0}}, st[32], seen[N] = {0}, n = 0;
  st[n++] = 0;
  while (n) {
    int u = st[--n];
    if (seen[u])
      continue;
    seen[u] = 1;
    printf("%d ", u);
    for (int i = g[u][0]; i > 0; i--)
      st[n++] = g[u][i];
  }
  puts("");
}
