#include "leetcode/problems/minimum-number-of-steps-to-make-two-strings-anagram-ii.h"

#include <algorithm>
#include <array>
#include <string>

namespace leetcode::problem_2186 {

static int minStepsImpl(const std::string& s, const std::string& t) {
  std::array<int, 26> cnt{};
  for (char c : s) {
    ++cnt[c - 'a'];
  }
  for (char c : t) {
    --cnt[c - 'a'];
  }
  int result = 0;
  for (int v : cnt) {
    result += std::abs(v);
  }
  return result;
}

MinimumNumberOfStepsToMakeTwoStringsAnagramIiSolution::
    MinimumNumberOfStepsToMakeTwoStringsAnagramIiSolution() {
  setMetaInfo({.id = 2186,
               .title = "Minimum Number of Steps to Make Two Strings Anagram II",
               .url = "https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram-ii/"});

  registerStrategy(
      {.name = "Counting - L1 distance",
       .expected = "Accepted",
       .time_complexity = "O(n + m)",
       .space_complexity = "O(1)",
       .tags = {"Hash Table", "String", "Counting"}},
      minStepsImpl);
}

int MinimumNumberOfStepsToMakeTwoStringsAnagramIiSolution::minSteps(
    std::string s, std::string t) {
  return getSolution()(std::move(s), std::move(t));
}

}  // namespace leetcode::problem_2186
