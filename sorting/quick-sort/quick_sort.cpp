#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <vector>

void quick_sort(std::vector<int>& a, long lo, long hi) { long i = lo, j = hi; int pivot = a[static_cast<std::size_t>(lo + (hi - lo) / 2)]; while (i <= j) { while (a[static_cast<std::size_t>(i)] < pivot) ++i; while (a[static_cast<std::size_t>(j)] > pivot) --j; if (i <= j) std::swap(a[static_cast<std::size_t>(i++)], a[static_cast<std::size_t>(j--)]); } if (lo < j) quick_sort(a, lo, j); if (i < hi) quick_sort(a, i, hi); }

std::vector<int> quick_sort(std::vector<int> a) {
  if (!a.empty()) quick_sort(a, 0, static_cast<long>(a.size()) - 1); return a;
}

int main() { for (int v : quick_sort({5, 1, 4, 2, 8})) std::cout << v << ' ' ; std::cout << '\n'; }
