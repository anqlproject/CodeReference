// Directed weighted edge list; negative weights are allowed; reachable negative
// cycles are reported.
#include <iostream>
#include <limits>
#include <tuple>
#include <vector>
using E = std::tuple<int, int, int>;
std::vector<long long> bellman_ford(int n, const std::vector<E> &e, int s) {
  std::vector<long long> d(n, LLONG_MAX);
  d[s] = 0;
  for (int i = 1; i < n; i++) {
    bool c = false;
    for (auto [u, v, w] : e)
      if (d[u] != LLONG_MAX && d[u] + w < d[v])
        d[v] = d[u] + w, c = true;
    if (!c)
      break;
  }
  for (auto [u, v, w] : e)
    if (d[u] != LLONG_MAX && d[u] + w < d[v])
      throw std::invalid_argument("negative cycle");
  return d;
}
int main() {
  auto d = bellman_ford(3, {{0, 1, 4}, {0, 2, 5}, {1, 2, -2}}, 0);
  for (auto x : d)
    std::cout << x << ' ';
}
