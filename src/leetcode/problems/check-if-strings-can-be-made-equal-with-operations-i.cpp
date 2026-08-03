#include "leetcode/problems/check-if-strings-can-be-made-equal-with-operations-i.h"

namespace leetcode::problem_2839 {

namespace {

bool canBeEqualImpl(std::string s1, std::string s2) {
  // Positions 0 and 2 are interchangeable (swap i, i+2).
  // Positions 1 and 3 are interchangeable. Compare each parity group.
  auto groupMatch = [](const std::string& a, const std::string& b, int base) {
    std::vector<char> ga = {a[base], a[base + 2]};
    std::vector<char> gb = {b[base], b[base + 2]};
    std::sort(ga.begin(), ga.end());
    std::sort(gb.begin(), gb.end());
    return ga == gb;
  };
  return groupMatch(s1, s2, 0) && groupMatch(s1, s2, 1);
}

}  // namespace

bool CheckIfStringsCanBeMadeEqualWithOperationsISolution::canBeEqual(
    std::string s1, std::string s2) {
  return getSolution()(s1, s2);
}

CheckIfStringsCanBeMadeEqualWithOperationsISolution::
    CheckIfStringsCanBeMadeEqualWithOperationsISolution() {
  setMetaInfo({.id = 2839,
               .title = "Check if Strings Can be Made Equal With Operations I",
               .url = "https://leetcode.com/problems/check-if-strings-can-be-made-equal-with-operations-i/"});
  registerStrategy(
      {.name = "parity-group",
       .expected = "Accepted",
       .time_complexity = "O(1)",
       .space_complexity = "O(1)",
       .tags = {"String"}},
      canBeEqualImpl);
}

}  // namespace leetcode::problem_2839
