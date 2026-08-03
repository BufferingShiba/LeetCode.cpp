#include "leetcode/problems/reverse-string-ii.h"

#include <algorithm>
#include <string>

namespace leetcode {
namespace problem_541 {

namespace {

std::string reverseStrImpl(std::string s, int k) {
  const int n = static_cast<int>(s.size());
  for (int i = 0; i < n; i += 2 * k) {
    const int left = i;
    const int right = std::min(i + k, n);
    std::reverse(s.begin() + left, s.begin() + right);
  }
  return s;
}

}  // namespace

ReverseStringIiSolution::ReverseStringIiSolution() {
  setMetaInfo({.id = 541,
               .title = "Reverse String II",
               .url = "https://leetcode.com/problems/reverse-string-ii/"});
  registerStrategy(
      {.name = "simulation",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(n)",
       .tags = {"Two Pointers", "String"}},
      reverseStrImpl);
}

std::string ReverseStringIiSolution::reverseStr(std::string s, int k) {
  return getSolution()(std::move(s), k);
}

}  // namespace problem_541
}  // namespace leetcode
