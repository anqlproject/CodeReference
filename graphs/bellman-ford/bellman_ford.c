// Directed weighted edge list; negative weights are allowed; reachable negative
// cycles are reported.
#include <limits.h>
#include <stdio.h>
typedef struct {
  int u, v, w;
} E;
int main(void) {
  E e[] = {{0, 1, 4}, {0, 2, 5}, {1, 2, -2}};
  int d[] = {0, INT_MAX, INT_MAX}, n = 3;
  for (int i = 1; i < n; i++) {
    int c = 0;
    for (int j = 0; j < 3; j++)
      if (d[e[j].u] != INT_MAX && d[e[j].u] + e[j].w < d[e[j].v])
        d[e[j].v] = d[e[j].u] + e[j].w, c = 1;
    if (!c)
      break;
  }
  for (int j = 0; j < 3; j++)
    if (d[e[j].u] != INT_MAX && d[e[j].u] + e[j].w < d[e[j].v])
      return 1;
  for (int i = 0; i < n; i++)
    printf("%d ", d[i]);
}
