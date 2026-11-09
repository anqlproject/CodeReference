// Weighted adjacency lists require nonnegative weights; admissible heuristic
// estimates remaining cost.
#include <functional>
#include <iostream>
#include <queue>
#include <vector>
using G = std::vector<std::vector<std::pair<int, int>>>;
int a_star(const G &g, int s, int goal, std::function<int(int)> h) {
  std::vector<int> d(g.size(), INT_MAX);
  using T = std::tuple<int, int, int>;
  std::priority_queue<T, std::vector<T>, std::greater<T>> q;
  d[s] = 0;
  q.push({h(s), 0, s});
  while (!q.empty()) {
    auto [f, c, u] = q.top();
    q.pop();
    if (c != d[u])
      continue;
    if (u == goal)
      return c;
    for (auto [v, w] : g[u]) {
      if (w < 0)
        throw std::invalid_argument("negative edge");
      if (c + w < d[v])
        d[v] = c + w, q.push({d[v] + h(v), d[v], v});
    }
  }
  return -1;
}
int main() {
  std::cout << a_star({{{1, 2}, {2, 5}}, {{2, 1}}, {}}, 0, 2,
                      [](int) { return 0; });
}
