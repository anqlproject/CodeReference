#include <stdio.h>
long long euclidean_gcd(long long a, long long b) {
  if (a < 0)
    a = -a;
  if (b < 0)
    b = -b;
  while (b) {
    long long t = a % b;
    a = b;
    b = t;
  }
  return a;
}
int main(void) {
  printf("%lld\n", euclidean_gcd(48, 18));
}
