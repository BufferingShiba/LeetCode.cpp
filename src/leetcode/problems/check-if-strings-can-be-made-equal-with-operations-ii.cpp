#include "leetcode/problems/check-if-strings-can-be-made-equal-with-operations-ii.h"

#include <array>

namespace leetcode::problem_2840 {

namespace {

bool checkStringsImpl(std::string s1, std::string s2) {
  std::array<int, 26> even{};
  std::array<int, 26> odd{};
  const int n = static_cast<int>(s1.size());
  for (int i = 0; i < n; ++i) {
    if (i % 2 == 0) {
      even[s1[i] - 'a']++;
      even[s2[i] - 'a']--;
    } else {
      odd[s1[i] - 'a']++;
      odd[s2[i] - 'a']--;
    }
  }
  for (int c = 0; c < 26; ++c) {
    if (even[c] != 0 || odd[c] != 0) {
      return false;
    }
  }
  return true;
}

}  // namespace

CheckIfStringsCanBeMadeEqualWithOperationsIiSolution::
    CheckIfStringsCanBeMadeEqualWithOperationsIiSolution() {
  setMetaInfo({.id = 2840,
               .title = "Check if Strings Can be Made Equal With Operations II",
               .url = "https://leetcode.com/problems/check-if-strings-can-be-made-equal-with-operations-ii/"});
  registerStrategy(
      {.name = "parity-count",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"Hash Table", "String", "Sorting"}},
      checkStringsImpl);
}

bool CheckIfStringsCanBeMadeEqualWithOperationsIiSolution::checkStrings(
    std::string s1, std::string s2) {
  return getSolution()(s1, s2);
}

}  // namespace leetcode::problem_2840
