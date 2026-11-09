// Integer-indexed directed adjacency lists; visits only vertices reachable from
// start.
#include <iostream>
#include <vector>
std::vector<int> dfs(const std::vector<std::vector<int>> &g, int s) {
  std::vector<int> o, st{s};
  std::vector<bool> seen(g.size());
  while (!st.empty()) {
    int u = st.back();
    st.pop_back();
    if (seen[u])
      continue;
    seen[u] = true;
    o.push_back(u);
    for (auto i = g[u].rbegin(); i != g[u].rend(); ++i)
      st.push_back(*i);
  }
  return o;
}
int main() {
  for (int x : dfs({{1, 2}, {3}, {3}, {}}, 0))
    std::cout << x << ' ';
}
