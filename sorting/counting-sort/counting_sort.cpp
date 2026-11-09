#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <vector>

std::vector<int> counting_sort(std::vector<int> a) {
  // The integer range must be small enough for its count array to fit in
  // memory.
  if (a.empty())
    return a;
  auto bounds = std::minmax_element(a.begin(), a.end());
  long long min = *bounds.first, max = *bounds.second;
  std::vector<std::size_t> count(static_cast<std::size_t>(max - min + 1));
  for (int v : a)
    ++count[static_cast<std::size_t>(static_cast<long long>(v) - min)];
  std::size_t k = 0;
  for (std::size_t i = 0; i < count.size(); ++i)
    while (count[i]--)
      a[k++] = static_cast<int>(min + i);
  return a;
}

int main() {
  for (int v : counting_sort({5, 1, 4, 2, 8}))
    std::cout << v << ' ';
  std::cout << '\n';
}
