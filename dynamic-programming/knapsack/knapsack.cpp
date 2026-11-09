// 0/1 knapsack contract: weights and capacity are nonnegative; returns maximum
// value.
#include <iostream>
#include <vector>
int knapsack(const std::vector<int> &w, const std::vector<int> &v, int c) {
  std::vector<int> d(c + 1);
  for (int i = 0; i < (int)w.size(); i++)
    for (int j = c; j >= w[i]; j--)
      d[j] = std::max(d[j], d[j - w[i]] + v[i]);
  return d[c];
}
int main() {
  std::cout << knapsack({2, 3, 4}, {4, 5, 6}, 5);
}
