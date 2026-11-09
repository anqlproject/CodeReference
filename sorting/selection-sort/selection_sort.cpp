#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <vector>

std::vector<int> selection_sort(std::vector<int> a) {
  for (std::size_t i = 0; i < a.size(); ++i) {
    auto min = i;
    for (std::size_t j = i + 1; j < a.size(); ++j)
      if (a[j] < a[min])
        min = j;
    std::swap(a[i], a[min]);
  }
  return a;
}

int main() {
  for (int v : selection_sort({5, 1, 4, 2, 8}))
    std::cout << v << ' ';
  std::cout << '\n';
}
