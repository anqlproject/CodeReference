#include <iostream>
#include <vector>
std::vector<int> sieve_of_eratosthenes(int n) {
  std::vector<bool> p(n + 1, true);
  if (n >= 0)
    p[0] = false;
  if (n >= 1)
    p[1] = false;
  for (int i = 2; i * i <= n; i++)
    if (p[i])
      for (int j = i * i; j <= n; j += i)
        p[j] = false;
  std::vector<int> o;
  for (int i = 2; i <= n; i++)
    if (p[i])
      o.push_back(i);
  return o;
}
int main() {
  for (int x : sieve_of_eratosthenes(30))
    std::cout << x << ' ';
}
