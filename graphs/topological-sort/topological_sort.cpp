// Directed adjacency lists; returns no ordering when a directed cycle exists.
#include <iostream>
#include <queue>
#include <vector>
std::vector<int> topological_sort(const std::vector<std::vector<int>> &g) {
  std::vector<int> d(g.size()), o;
  for (auto &r : g)
    for (int v : r)
      d[v]++;
  std::queue<int> q;
  for (int i = 0; i < (int)d.size(); i++)
    if (!d[i])
      q.push(i);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    o.push_back(u);
    for (int v : g[u])
      if (--d[v] == 0)
        q.push(v);
  }
  if (o.size() != g.size())
    return {};
  return o;
}
int main() {
  for (int x : topological_sort({{1, 2}, {3}, {3}, {}}))
    std::cout << x << ' ';
}
