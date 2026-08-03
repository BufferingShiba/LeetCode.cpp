#include "leetcode/problems/max-consecutive-ones.h"

#include <algorithm>

namespace leetcode {
namespace problem_485 {
namespace {

int findMaxConsecutiveOnesImpl(std::vector<int>& nums) {
  int maxCount = 0;
  int cur = 0;
  for (int num : nums) {
    if (num == 1) {
      ++cur;
      maxCount = std::max(maxCount, cur);
    } else {
      cur = 0;
    }
  }
  return maxCount;
}

}  // namespace

MaxConsecutiveOnesSolution::MaxConsecutiveOnesSolution() {
  setMetaInfo({.id = 485,
               .title = "Max Consecutive Ones",
               .url = "https://leetcode.com/problems/max-consecutive-ones/"});
  registerStrategy({.name = "LinearScan",
                    .expected = "Accepted",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(1)",
                    .tags = {"Array"}},
                   findMaxConsecutiveOnesImpl);
}

int MaxConsecutiveOnesSolution::findMaxConsecutiveOnes(std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace problem_485
}  // namespace leetcode
