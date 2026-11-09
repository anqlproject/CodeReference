// Input is sorted ascending; when duplicates occur, any matching index may be
// returned.
#include <iostream>
#include <vector>
int interpolation_search(const std::vector<int> &a, int x) {
  int l = 0, r = (int)a.size() - 1;
  while (l <= r && a[l] <= x && x <= a[r]) {
    if (a[l] == a[r])
      return a[l] == x ? l : -1;
    int p = l + (long long)(x - a[l]) * (r - l) / (a[r] - a[l]);
    if (a[p] == x)
      return p;
    if (a[p] < x)
      l = p + 1;
    else
      r = p - 1;
  }
  return -1;
}
int main() {
  std::cout << interpolation_search({1, 2, 2, 4}, 2) << '\n';
}
