#include "leetcode/problems/frog-jump.h"

#include <unordered_map>
#include <unordered_set>
#include <vector>

namespace leetcode {
namespace problem_403 {

static bool canCrossImpl(std::vector<int>& stones) {
  int n = stones.size();
  // First jump must be exactly 1 unit
  if (n < 2 || stones[1] != 1) return false;
  if (n == 2) return true;

  // Map stone position to index for quick lookup
  std::unordered_map<int, int> posToIndex;
  for (int i = 0; i < n; ++i) {
    posToIndex[stones[i]] = i;
  }

  // dp[i] = set of possible last jump lengths to reach stones[i]
  std::vector<std::unordered_set<int>> dp(n);
  dp[0].insert(0);  // initial: at stone 0, last jump = 0 (next jump must be 1)

  for (int i = 0; i < n; ++i) {
    for (int k : dp[i]) {
      for (int step = k - 1; step <= k + 1; ++step) {
        if (step <= 0) continue;
        int nextPos = stones[i] + step;
        auto it = posToIndex.find(nextPos);
        if (it != posToIndex.end()) {
          int nextIdx = it->second;
          if (nextIdx == n - 1) return true;  // early exit
          dp[nextIdx].insert(step);
        }
      }
    }
  }

  return !dp[n - 1].empty();
}

FrogJumpSolution::FrogJumpSolution() {
  setMetaInfo({.id = 403, .title = "Frog Jump", .url = "https://leetcode.com/problems/frog-jump/"});
  registerStrategy({
    .name = "DP with HashSets",
    .expected = "Accepted",
    .time_complexity = "O(n²)",
    .space_complexity = "O(n²)",
    .tags = {"Array", "Dynamic Programming"}
  }, canCrossImpl);
}

bool FrogJumpSolution::canCross(std::vector<int>& stones) {
  return getSolution()(stones);
}

}  // namespace problem_403
}  // namespace leetcode
