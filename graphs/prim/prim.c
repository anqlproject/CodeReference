// Undirected weighted adjacency lists; returns failure when the graph is
// disconnected.
#include <limits.h>
#include <stdio.h>
int main(void) { /* undirected weighted adjacency lists */
  int g[3][2][2] = {{{1, 4}, {2, 5}}, {{0, 4}, {2, 2}}, {{0, 5}, {1, 2}}},
      d[] = {2, 2, 2}, s[] = {1, 0, 0}, sum = 0;
  for (int k = 1; k < 3; k++) {
    int v = -1, w = INT_MAX;
    for (int u = 0; u < 3; u++)
      if (s[u])
        for (int j = 0; j < d[u]; j++)
          if (!s[g[u][j][0]] && g[u][j][1] < w)
            v = g[u][j][0], w = g[u][j][1];
    if (v < 0)
      return 1;
    s[v] = 1;
    sum += w;
  }
  printf("%d\n", sum);
}
