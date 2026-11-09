#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <vector>

std::vector<int> bucket_sort(std::vector<int> a) {
  if (a.size() < 2) return a; auto bounds = std::minmax_element(a.begin(), a.end()); long long min = *bounds.first, max = *bounds.second; if (min == max) return a; std::vector<std::vector<int>> buckets(a.size()); long long span = max - min + 1; for (int v : a) { std::size_t b = static_cast<std::size_t>((static_cast<long long>(v) - min) * a.size() / span); if (b >= a.size()) b = a.size() - 1; buckets[b].push_back(v); } std::size_t k = 0; for (auto &bucket : buckets) { for (std::size_t i = 1; i < bucket.size(); ++i) { int v = bucket[i]; std::size_t j = i; while (j > 0 && bucket[j - 1] > v) { bucket[j] = bucket[j - 1]; --j; } bucket[j] = v; } for (int v : bucket) a[k++] = v; } return a;
}

int main() { for (int v : bucket_sort({5, 1, 4, 2, 8})) std::cout << v << ' ' ; std::cout << '\n'; }
