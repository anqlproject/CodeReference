#include <iostream>
#include <vector>
int linear_search(const std::vector<int> &a, int x) {
  for (int i = 0; i < (int)a.size(); i++)
    if (a[i] == x)
      return i;
  return -1;
}
int main() {
  std::cout << linear_search({4, 2, 7}, 2) << '\n';
}
