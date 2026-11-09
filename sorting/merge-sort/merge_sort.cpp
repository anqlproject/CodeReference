#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <vector>

void merge_sort(std::vector<int> &a, std::vector<int> &temp, std::size_t lo,
                std::size_t hi) {
  if (hi - lo < 2)
    return;
  auto mid = lo + (hi - lo) / 2;
  merge_sort(a, temp, lo, mid);
  merge_sort(a, temp, mid, hi);
  auto i = lo, j = mid, k = lo;
  while (i < mid || j < hi)
    temp[k++] = (j == hi || (i < mid && a[i] <= a[j])) ? a[i++] : a[j++];
  std::copy(temp.begin() + lo, temp.begin() + hi, a.begin() + lo);
}

std::vector<int> merge_sort(std::vector<int> a) {
  std::vector<int> temp(a.size());
  merge_sort(a, temp, 0, a.size());
  return a;
}

int main() {
  for (int v : merge_sort({5, 1, 4, 2, 8}))
    std::cout << v << ' ';
  std::cout << '\n';
}
