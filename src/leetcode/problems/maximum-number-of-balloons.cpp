#include "leetcode/problems/maximum-number-of-balloons.h"

#include <algorithm>
#include <array>
#include <string>

namespace leetcode::problem_1189 {

namespace {

int maxNumberOfBalloonsImpl(std::string text) {
  std::array<int, 26> count{};
  for (char ch : text) {
    ++count[ch - 'a'];
  }
  int ans = count['b' - 'a'];
  ans = std::min(ans, count['a' - 'a']);
  ans = std::min(ans, count['l' - 'a'] / 2);
  ans = std::min(ans, count['o' - 'a'] / 2);
  ans = std::min(ans, count['n' - 'a']);
  return ans;
}

}  // namespace

MaximumNumberOfBalloonsSolution::MaximumNumberOfBalloonsSolution() {
  setMetaInfo({.id = 1189,
               .title = "Maximum Number of Balloons",
               .url = "https://leetcode.com/problems/maximum-number-of-balloons/"});
  registerStrategy(
      {.name = "counting",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"Hash Table", "String", "Counting"}},
      maxNumberOfBalloonsImpl);
}

int MaximumNumberOfBalloonsSolution::maxNumberOfBalloons(std::string text) {
  return getSolution()(text);
}

}  // namespace leetcode::problem_1189
