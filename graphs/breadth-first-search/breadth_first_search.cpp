// Integer-indexed directed adjacency lists; visits only vertices reachable from
// start.
#include <iostream>
#include <queue>
#include <vector>
std::vector<int> bfs(const std::vector<std::vector<int>> &g, int s) {
  std::vector<int> o;
  std::vector<bool> seen(g.size());
  std::queue<int> q;
  q.push(s);
  seen[s] = true;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    o.push_back(u);
    for (int v : g[u])
      if (!seen[v])
        seen[v] = true, q.push(v);
  }
  return o;
}
int main() {
  for (int x : bfs({{1, 2}, {3}, {3}, {}}, 0))
    std::cout << x << ' ';
}
