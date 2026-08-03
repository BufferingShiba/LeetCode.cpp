#include "leetcode/problems/frog-jump-ii.h"

#include <algorithm>

namespace leetcode {
namespace problem_2498 {

int FrogJumpIiSolution::maxJumpImpl(std::vector<int>& stones) {
  const int n = static_cast<int>(stones.size());
  if (n == 2) {
    return stones[1] - stones[0];
  }
  int ans = 0;
  // Maximum jump must cover every gap of index distance 2 across forward+back
  // interleaved traversal, plus the first and last adjacent gaps.
  for (int i = 2; i < n; ++i) {
    ans = std::max(ans, stones[i] - stones[i - 2]);
  }
  ans = std::max(ans, stones[1] - stones[0]);
  ans = std::max(ans, stones[n - 1] - stones[n - 2]);
  return ans;
}

}  // namespace problem_2498
}  // namespace leetcode
