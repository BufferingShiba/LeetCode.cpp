#include "leetcode/problems/teemo-attacking.h"

namespace leetcode {
namespace problem_495 {

namespace {

int findPoisonedDurationImpl(std::vector<int>& timeSeries, int duration) {
  if (timeSeries.empty()) {
    return 0;
  }
  long long total = 0;
  for (size_t i = 0; i + 1 < timeSeries.size(); ++i) {
    total += std::min<long long>(duration,
                                 timeSeries[i + 1] - timeSeries[i]);
  }
  total += duration;
  return static_cast<int>(total);
}

}  // namespace

TeemoAttackingSolution::TeemoAttackingSolution() {
  setMetaInfo({.id = 495,
               .title = "Teemo Attacking",
               .url = "https://leetcode.com/problems/teemo-attacking/"});
  registerStrategy(
      {.name = "LinearScan",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"Array", "Simulation"}},
      findPoisonedDurationImpl);
}

int TeemoAttackingSolution::findPoisonedDuration(std::vector<int>& timeSeries,
                                                 int duration) {
  return getSolution()(timeSeries, duration);
}

}  // namespace problem_495
}  // namespace leetcode
