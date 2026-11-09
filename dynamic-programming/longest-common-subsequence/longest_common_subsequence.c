// Returns the length of a longest common subsequence.
#include <stdio.h>
#include <string.h>
int main(void) {
  char *a = "ABCBDAB", *b = "BDCAB";
  int d[16] = {0}, n = strlen(b);
  for (int i = 0; a[i]; i++) {
    int p = 0;
    for (int j = 1; j <= n; j++) {
      int old = d[j];
      d[j] = a[i] == b[j - 1] ? p + 1 : (d[j] > d[j - 1] ? d[j] : d[j - 1]);
      p = old;
    }
  }
  printf("%d\n", d[n]);
}
