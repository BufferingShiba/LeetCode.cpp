#include "leetcode/problems/find-the-maximum-achievable-number.h"

#include <string>
#include <utility>
#include <vector>

namespace leetcode::problem_2769 {

namespace {

int theMaximumAchievableXImpl(int num, int t) {
  return num + 2 * t;
}

}  // namespace

FindTheMaximumAchievableNumberSolution::FindTheMaximumAchievableNumberSolution() {
  setMetaInfo({.id = 2769,
               .title = "Find the Maximum Achievable Number",
               .url = "https://leetcode.com/problems/find-the-maximum-achievable-number/"});

  registerStrategy(
      {.name = "math",
       .expected = "Accepted",
       .time_complexity = "O(1)",
       .space_complexity = "O(1)",
       .tags = {"Math"}},
      theMaximumAchievableXImpl);
}

int FindTheMaximumAchievableNumberSolution::theMaximumAchievableX(int num, int t) {
  return getSolution()(num, t);
}

}  // namespace leetcode::problem_2769
