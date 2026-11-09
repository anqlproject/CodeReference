// Integer-indexed directed adjacency lists; visits only vertices reachable from
// start.
#include <stdio.h>
#define N 4
int main(void) { /* adjacency lists: each row starts with its degree */
  int g[N][4] = {{2, 1, 2}, {1, 3}, {1, 3}, {0}}, q[N], seen[N] = {0}, h = 0,
      t = 0;
  q[t++] = 0;
  seen[0] = 1;
  while (h < t) {
    int u = q[h++];
    printf("%d ", u);
    for (int i = 1; i <= g[u][0]; i++) {
      int v = g[u][i];
      if (!seen[v])
        seen[v] = 1, q[t++] = v;
    }
  }
  puts("");
}
