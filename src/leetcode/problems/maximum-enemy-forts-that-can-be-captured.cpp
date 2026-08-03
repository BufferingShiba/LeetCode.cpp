#include "leetcode/problems/maximum-enemy-forts-that-can-be-captured.h"

#include <algorithm>

namespace leetcode {
namespace problem_2511 {

namespace {

int captureFortsImpl(std::vector<int>& forts) {
  int n = static_cast<int>(forts.size());
  int ans = 0;
  int i = 0;
  while (i < n) {
    if (forts[i] == 0) {
      ++i;
      continue;
    }
    // forts[i] is non-zero. Move j forward while zeros.
    int j = i + 1;
    while (j < n && forts[j] == 0) {
      ++j;
    }
    if (j < n && forts[j] != forts[i]) {
      ans = std::max(ans, j - i - 1);
    }
    i = j;
  }
  return ans;
}

}  // namespace

MaximumEnemyFortsThatCanBeCapturedSolution::
    MaximumEnemyFortsThatCanBeCapturedSolution() {
  setMetaInfo({.id = 2511,
               .title = "Maximum Enemy Forts That Can Be Captured",
               .url = "https://leetcode.com/problems/maximum-enemy-forts-that-can-be-captured/"});
  registerStrategy({.name = "TwoPointersScan",
                    .expected = "Accepted",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(1)",
                    .tags = {"Array", "Two Pointers"}},
                   captureFortsImpl);
}

int MaximumEnemyFortsThatCanBeCapturedSolution::captureForts(
    std::vector<int>& forts) {
  return getSolution()(forts);
}

}  // namespace problem_2511
}  // namespace leetcode
