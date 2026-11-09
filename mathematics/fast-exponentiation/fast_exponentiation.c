#include <stdio.h>
double fast_exponentiation(double b, int e) {
  if (e < 0)
    return 1 / fast_exponentiation(b, -e);
  double r = 1;
  while (e) {
    if (e & 1)
      r *= b;
    b *= b;
    e >>= 1;
  }
  return r;
}
int main(void) {
  printf("%.0f\n", fast_exponentiation(2, 10));
}
