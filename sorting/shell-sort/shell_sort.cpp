#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <vector>

std::vector<int> shell_sort(std::vector<int> a) {
  for (std::size_t gap = a.size() / 2; gap > 0; gap /= 2)
    for (std::size_t i = gap; i < a.size(); ++i) {
      int v = a[i];
      std::size_t j = i;
      while (j >= gap && a[j - gap] > v) {
        a[j] = a[j - gap];
        j -= gap;
      }
      a[j] = v;
    }
  return a;
}

int main() {
  for (int v : shell_sort({5, 1, 4, 2, 8}))
    std::cout << v << ' ';
  std::cout << '\n';
}
