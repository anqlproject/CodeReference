#include <cstdlib>
#include <iostream>
long long euclidean_gcd(long long a, long long b) {
  a = std::llabs(a);
  b = std::llabs(b);
  while (b) {
    auto t = a % b;
    a = b;
    b = t;
  }
  return a;
}
int main() {
  std::cout << euclidean_gcd(48, 18);
}
