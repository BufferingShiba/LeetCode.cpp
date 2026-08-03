#include "leetcode/problems/maximum-population-year.h"

#include <algorithm>
#include <utility>

namespace leetcode {
namespace problem_1854 {

namespace {

constexpr int kMinYear = 1950;
constexpr int kMaxYear = 2050;
constexpr int kRange = kMaxYear - kMinYear + 1;

int maximumPopulationImpl(std::vector<std::vector<int>>& logs) {
  std::vector<int> delta(kRange + 1, 0);
  for (const auto& log : logs) {
    ++delta[log[0] - kMinYear];
    --delta[log[1] - kMinYear];
  }

  int bestYear = kMinYear;
  int bestPop = 0;
  int cur = 0;
  for (int i = 0; i < kRange; ++i) {
    cur += delta[i];
    if (cur > bestPop) {
      bestPop = cur;
      bestYear = kMinYear + i;
    }
  }
  return bestYear;
}

}  // namespace

MaximumPopulationYearSolution::MaximumPopulationYearSolution() {
  setMetaInfo({.id = 1854,
               .title = "Maximum Population Year",
               .url = "https://leetcode.com/problems/maximum-population-year/"});

  registerStrategy(
      {.name = "DifferenceArrayPrefixSum",
       .expected = "Accepted",
       .time_complexity = "O(n + R)",
       .space_complexity = "O(R)",
       .tags = {"Array", "Counting", "Prefix Sum"}},
      maximumPopulationImpl);
}

int MaximumPopulationYearSolution::maximumPopulation(
    std::vector<std::vector<int>>& logs) {
  return getSolution()(logs);
}

}  // namespace problem_1854
}  // namespace leetcode
