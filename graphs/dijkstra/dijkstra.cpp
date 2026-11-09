// Weighted adjacency lists; edge weights must be nonnegative.
#include <iostream>
#include <limits>
#include <queue>
#include <vector>
using G = std::vector<std::vector<std::pair<int, int>>>;
std::vector<long long> dijkstra(const G &g, int s) {
  std::vector<long long> d(g.size(), LLONG_MAX);
  using P = std::pair<long long, int>;
  std::priority_queue<P, std::vector<P>, std::greater<P>> q;
  d[s] = 0;
  q.push({0, s});
  while (!q.empty()) {
    auto [du, u] = q.top();
    q.pop();
    if (du != d[u])
      continue;
    for (auto [v, w] : g[u]) {
      if (w < 0)
        throw std::invalid_argument("negative edge");
      if (du + w < d[v])
        d[v] = du + w, q.push({d[v], v});
    }
  }
  return d;
}
int main() {
  auto d = dijkstra({{{1, 2}, {2, 5}}, {{2, 1}}, {}}, 0);
  for (auto x : d)
    std::cout << x << ' ';
}
