#include <stdio.h>
int main(void) {
  int n = 30, p[31];
  for (int i = 0; i <= n; i++)
    p[i] = 1;
  p[0] = p[1] = 0;
  for (int i = 2; i * i <= n; i++)
    if (p[i])
      for (int j = i * i; j <= n; j += i)
        p[j] = 0;
  for (int i = 2; i <= n; i++)
    if (p[i])
      printf("%d ", i);
  puts("");
}
