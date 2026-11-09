// Undirected weighted edge list; returns failure when the graph is
// disconnected.
#include <algorithm>
#include <iostream>
#include <vector>
struct E {
  int u, v, w;
};
long long kruskal(int n, std::vector<E> e) {
  for (std::size_t i = 1; i < e.size(); ++i) {
    auto x = e[i];
    std::size_t j = i;
    while (j > 0 && e[j - 1].w > x.w) {
      e[j] = e[j - 1];
      --j;
    }
    e[j] = x;
  }
  std::vector<int> p(n);
  for (int i = 0; i < n; i++)
    p[i] = i;
  auto f = [&](auto &&self, int x) -> int {
    return p[x] == x ? x : p[x] = self(self, p[x]);
  };
  long long s = 0;
  int k = 0;
  for (auto x : e) {
    int a = f(f, x.u), b = f(f, x.v);
    if (a != b)
      p[a] = b, s += x.w, k++;
  }
  return k == std::max(0, n - 1) ? s : -1;
}
int main() {
  std::cout << kruskal(3, {{0, 1, 4}, {1, 2, 2}, {0, 2, 5}});
}
