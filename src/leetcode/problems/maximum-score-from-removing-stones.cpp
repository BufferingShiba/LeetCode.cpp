#include "leetcode/problems/maximum-score-from-removing-stones.h"

#include <algorithm>

namespace leetcode {
namespace problem_1753 {
namespace {

int maximumScoreImpl(int a, int b, int c) {
  const int total = a + b + c;
  const int largest = std::max({a, b, c});
  return std::min(total / 2, total - largest);
}

}  // namespace

MaximumScoreFromRemovingStonesSolution::MaximumScoreFromRemovingStonesSolution() {
  setMetaInfo({.id = 1753,
               .title = "Maximum Score From Removing Stones",
               .url = "https://leetcode.com/problems/maximum-score-from-removing-stones/"});
  registerStrategy(
      {.name = "GreedyMath",
       .expected = "Accepted",
       .time_complexity = "O(1)",
       .space_complexity = "O(1)",
       .tags = {"Math", "Greedy"}},
      maximumScoreImpl);
}

int MaximumScoreFromRemovingStonesSolution::maximumScore(int a, int b, int c) {
  return getSolution()(a, b, c);
}

}  // namespace problem_1753
}  // namespace leetcode
