#include <stdio.h>
long long fibonacci(int n) {
  long long a = 0, b = 1;
  for (int i = 0; i < n; i++) {
    long long t = a + b;
    a = b;
    b = t;
  }
  return a;
}
int main(void) {
  printf("%lld\n", fibonacci(10));
}
