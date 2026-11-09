// Directed adjacency lists; returns no ordering when a directed cycle exists.
#include <stdio.h>
int main(void) {
  int g[4][3] = {{2, 1, 2}, {1, 3}, {1, 3}, {0}}, d[] = {0, 0, 0, 0}, q[4],
      h = 0, t = 0, o = 0;
  for (int u = 0; u < 4; u++)
    for (int j = 1; j <= g[u][0]; j++)
      d[g[u][j]]++;
  for (int i = 0; i < 4; i++)
    if (!d[i])
      q[t++] = i;
  while (h < t) {
    int u = q[h++];
    printf("%d ", u);
    o++;
    for (int j = 1; j <= g[u][0]; j++)
      if (--d[g[u][j]] == 0)
        q[t++] = g[u][j];
  }
  if (o < 4)
    puts("cycle");
}
