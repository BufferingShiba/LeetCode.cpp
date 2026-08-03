#include "leetcode/problems/check-if-one-string-swap-can-make-strings-equal.h"

namespace leetcode::problem_1790 {

namespace {

bool areAlmostEqualImpl(std::string s1, std::string s2) {
  if (s1 == s2) return true;

  int first = -1, second = -1;
  for (int i = 0; i < static_cast<int>(s1.size()); ++i) {
    if (s1[i] != s2[i]) {
      if (first == -1) {
        first = i;
      } else if (second == -1) {
        second = i;
      } else {
        return false;  // more than 2 mismatches
      }
    }
  }

  // exactly 2 mismatches
  return second != -1 && s1[first] == s2[second] && s1[second] == s2[first];
}

}  // namespace

CheckIfOneStringSwapCanMakeStringsEqualSolution::CheckIfOneStringSwapCanMakeStringsEqualSolution() {
  setMetaInfo({.id = 1790,
               .title = "Check if One String Swap Can Make Strings Equal",
               .url = "https://leetcode.com/problems/check-if-one-string-swap-can-make-strings-equal/"});

  registerStrategy(
      {.name = "Single-pass mismatch count",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"string", "counting"}},
      areAlmostEqualImpl);
}

bool CheckIfOneStringSwapCanMakeStringsEqualSolution::areAlmostEqual(std::string s1, std::string s2) {
  return getSolution()(std::move(s1), std::move(s2));
}

}  // namespace leetcode::problem_1790
