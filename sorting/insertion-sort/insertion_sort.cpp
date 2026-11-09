#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <vector>

std::vector<int> insertion_sort(std::vector<int> a) {
  for (std::size_t i = 1; i < a.size(); ++i) {
    int v = a[i];
    std::size_t j = i;
    while (j > 0 && a[j - 1] > v) {
      a[j] = a[j - 1];
      --j;
    }
    a[j] = v;
  }
  return a;
}

int main() {
  for (int v : insertion_sort({5, 1, 4, 2, 8}))
    std::cout << v << ' ';
  std::cout << '\n';
}
