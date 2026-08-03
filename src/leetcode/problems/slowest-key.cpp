#include "leetcode/problems/slowest-key.h"

#include <utility>

namespace leetcode {
namespace problem_1629 {

namespace {

char slowestKeyImpl(std::vector<int>& releaseTimes, std::string keysPressed) {
  char best = keysPressed[0];
  int bestDuration = releaseTimes[0];
  for (int i = 1; i < static_cast<int>(keysPressed.size()); ++i) {
    int duration = releaseTimes[i] - releaseTimes[i - 1];
    if (duration > bestDuration ||
        (duration == bestDuration && keysPressed[i] > best)) {
      bestDuration = duration;
      best = keysPressed[i];
    }
  }
  return best;
}

}  // namespace

SlowestKeySolution::SlowestKeySolution() {
  setMetaInfo({.id = 1629,
               .title = "Slowest Key",
               .url = "https://leetcode.com/problems/slowest-key/"});
  registerStrategy({.name = "LinearScan",
                    .expected = "Accepted",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(1)",
                    .tags = {"Array", "String"}},
                   slowestKeyImpl);
}

char SlowestKeySolution::slowestKey(std::vector<int>& releaseTimes,
                                    std::string keysPressed) {
  return getSolution()(releaseTimes, std::move(keysPressed));
}

}  // namespace problem_1629
}  // namespace leetcode
