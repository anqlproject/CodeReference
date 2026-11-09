// Undirected weighted adjacency lists; returns failure when the graph is
// disconnected.
#include <climits>
#include <iostream>
#include <vector>
using G = std::vector<std::vector<std::pair<int, int>>>;
long long prim(const G &g) {
  if (g.empty())
    return 0;
  std::vector<bool> s(g.size());
  s[0] = true;
  int n = 1;
  long long sum = 0;
  while (n < (int)g.size()) {
    int v = -1, w = INT_MAX;
    for (int u = 0; u < (int)g.size(); u++)
      if (s[u])
        for (auto [x, c] : g[u])
          if (!s[x] && c < w)
            v = x, w = c;
    if (v < 0)
      return -1;
    s[v] = true;
    n++;
    sum += w;
  }
  return sum;
}
int main() {
  std::cout << prim({{{1, 4}, {2, 5}}, {{0, 4}, {2, 2}}, {{0, 5}, {1, 2}}});
}
