// Returns the length of a longest common subsequence.
#include <iostream>
#include <string>
#include <vector>
int longest_common_subsequence(std::string a, std::string b) {
  std::vector<int> d(b.size() + 1);
  for (char x : a) {
    int p = 0;
    for (std::size_t j = 1; j <= b.size(); j++) {
      int old = d[j];
      d[j] = x == b[j - 1] ? p + 1 : std::max(d[j], d[j - 1]);
      p = old;
    }
  }
  return d.back();
}
int main() {
  std::cout << longest_common_subsequence("ABCBDAB", "BDCAB");
}
