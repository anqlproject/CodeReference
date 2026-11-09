#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <vector>

std::vector<int> radix_sort(std::vector<int> a) {
  for (int v : a)
    if (v < 0)
      throw std::invalid_argument(
          "radix sort supports non-negative integers only");
  int max = a.empty() ? 0 : *std::max_element(a.begin(), a.end());
  std::vector<int> out(a.size());
  for (long long exp = 1; max / exp > 0; exp *= 10) {
    std::size_t count[10] = {};
    for (int v : a)
      ++count[(v / exp) % 10];
    for (int i = 1; i < 10; ++i)
      count[i] += count[i - 1];
    for (std::size_t i = a.size(); i > 0; --i) {
      std::size_t d = static_cast<std::size_t>((a[i - 1] / exp) % 10);
      out[--count[d]] = a[i - 1];
    }
    a.swap(out);
  }
  return a;
}

int main() {
  for (int v : radix_sort({5, 1, 4, 2, 8}))
    std::cout << v << ' ';
  std::cout << '\n';
}
