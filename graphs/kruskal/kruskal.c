// Undirected weighted edge list; returns failure when the graph is
// disconnected.
#include <stdio.h>
typedef struct {
  int u, v, w;
} E;
int f(int *p, int x) {
  return p[x] == x ? x : (p[x] = f(p, p[x]));
}
int main(void) {
  E e[] = {{0, 1, 4}, {1, 2, 2}, {0, 2, 5}};
  int p[] = {0, 1, 2}, sum = 0, k = 0;
  for (int i = 0; i < 3; i++) {
    int m = i;
    for (int j = i + 1; j < 3; j++)
      if (e[j].w < e[m].w)
        m = j;
    E t = e[i];
    e[i] = e[m];
    e[m] = t;
  }
  for (int i = 0; i < 3; i++) {
    int a = f(p, e[i].u), b = f(p, e[i].v);
    if (a != b)
      p[a] = b, sum += e[i].w, k++;
  }
  printf("%d\n", k == 2 ? sum : -1);
}
