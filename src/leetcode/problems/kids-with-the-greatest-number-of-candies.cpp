#include "leetcode/problems/kids-with-the-greatest-number-of-candies.h"

#include <algorithm>

namespace leetcode::problem_1431 {

namespace {

std::vector<bool> kidsWithCandiesImpl(std::vector<int>& candies,
                                      int extraCandies) {
  const int maxCandies = *std::max_element(candies.begin(), candies.end());
  std::vector<bool> result;
  result.reserve(candies.size());
  for (int c : candies) {
    result.push_back(c + extraCandies >= maxCandies);
  }
  return result;
}

}  // namespace

KidsWithTheGreatestNumberOfCandiesSolution::
    KidsWithTheGreatestNumberOfCandiesSolution() {
  setMetaInfo({.id = 1431,
               .title = "Kids With the Greatest Number of Candies",
               .url = "https://leetcode.com/problems/kids-with-the-greatest-"
                      "number-of-candies/"});
  registerStrategy(
      {.name = "SinglePassMax",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(n)",
       .tags = {"Array"}},
      kidsWithCandiesImpl);
}

std::vector<bool> KidsWithTheGreatestNumberOfCandiesSolution::kidsWithCandies(
    std::vector<int>& candies, int extraCandies) {
  return getSolution()(candies, extraCandies);
}

}  // namespace leetcode::problem_1431
