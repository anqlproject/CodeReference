#include <iostream>
#include <vector>
int binary_search(const std::vector<int> &a, int x) {
  int l = 0, r = (int)a.size() - 1;
  while (l <= r) {
    int m = l + (r - l) / 2;
    if (a[m] == x)
      return m;
    if (a[m] < x)
      l = m + 1;
    else
      r = m - 1;
  }
  return -1;
}
int main() {
  std::cout << binary_search({1, 3, 5, 7}, 5) << '\n';
}
