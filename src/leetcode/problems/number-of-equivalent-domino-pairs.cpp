#include "leetcode/problems/number-of-equivalent-domino-pairs.h"

namespace leetcode::problem_1128 {

namespace {

int numEquivDominoPairsImpl(std::vector<std::vector<int>>& dominoes) {
  int cnt[10][10] = {};
  int result = 0;
  for (const auto& d : dominoes) {
    int a = d[0];
    int b = d[1];
    if (a > b) std::swap(a, b);
    result += cnt[a][b];
    ++cnt[a][b];
  }
  return result;
}

}  // namespace

NumberOfEquivalentDominoPairsSolution::NumberOfEquivalentDominoPairsSolution() {
  setMetaInfo(
      {.id = 1128,
       .title = "Number of Equivalent Domino Pairs",
       .url =
           "https://leetcode.com/problems/number-of-equivalent-domino-pairs/"});
  registerStrategy(
      {.name = "hash-count",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"Array", "Hash Table", "Counting"}},
      numEquivDominoPairsImpl);
}

int NumberOfEquivalentDominoPairsSolution::numEquivDominoPairs(
    std::vector<std::vector<int>>& dominoes) {
  return getSolution()(dominoes);
}

}  // namespace leetcode::problem_1128
