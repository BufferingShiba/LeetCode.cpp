#include "leetcode/problems/maximum-score-of-a-good-subarray.h"

#include <algorithm>
#include <vector>

namespace leetcode {
namespace problem_1793 {

static int maximumScoreImpl(std::vector<int>& nums, int k) {
  int n = nums.size();
  int l = k, r = k;
  int curMin = nums[k];
  int ans = curMin;  // width = 1

  while (l > 0 || r < n - 1) {
    if (l == 0) {
      ++r;
      curMin = std::min(curMin, nums[r]);
    } else if (r == n - 1) {
      --l;
      curMin = std::min(curMin, nums[l]);
    } else if (nums[l - 1] >= nums[r + 1]) {
      --l;
      curMin = std::min(curMin, nums[l]);
    } else {
      ++r;
      curMin = std::min(curMin, nums[r]);
    }
    ans = std::max(ans, curMin * (r - l + 1));
  }
  return ans;
}

int MaximumScoreOfAGoodSubarraySolution::maximumScore(std::vector<int>& nums, int k) {
  return getSolution()(nums, k);
}

MaximumScoreOfAGoodSubarraySolution::MaximumScoreOfAGoodSubarraySolution() {
  setMetaInfo({.id = 1793, .title = "Maximum Score of a Good Subarray", .url = "https://leetcode.com/problems/maximum-score-of-a-good-subarray/"});
  registerStrategy({.name = "TwoPointers", .expected = "Accepted", .time_complexity = "O(n)", .space_complexity = "O(1)", .tags = {"Array", "Two Pointers", "Greedy"}}, maximumScoreImpl);
}

} // namespace problem_1793
} // namespace leetcode
