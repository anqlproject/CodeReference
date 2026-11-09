#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <vector>

std::vector<int> bubble_sort(std::vector<int> a) {
  for (std::size_t end = a.size(); end > 1; --end) {
    bool swapped = false;
    for (std::size_t i = 0; i + 1 < end; ++i)
      if (a[i] > a[i + 1]) {
        std::swap(a[i], a[i + 1]);
        swapped = true;
      }
    if (!swapped)
      break;
  }
  return a;
}

int main() {
  for (int v : bubble_sort({5, 1, 4, 2, 8}))
    std::cout << v << ' ';
  std::cout << '\n';
}
