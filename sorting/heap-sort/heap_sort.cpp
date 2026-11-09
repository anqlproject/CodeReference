#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <vector>

void sift(std::vector<int>& a, std::size_t root, std::size_t size) { while (root * 2 + 1 < size) { auto child = root * 2 + 1; if (child + 1 < size && a[child] < a[child + 1]) ++child; if (a[root] >= a[child]) break; std::swap(a[root], a[child]); root = child; } }

std::vector<int> heap_sort(std::vector<int> a) {
  for (std::size_t i = a.size() / 2; i > 0; --i) sift(a, i - 1, a.size()); for (std::size_t end = a.size(); end > 1; --end) { std::swap(a[0], a[end - 1]); sift(a, 0, end - 1); } return a;
}

int main() { for (int v : heap_sort({5, 1, 4, 2, 8})) std::cout << v << ' ' ; std::cout << '\n'; }
