#include "leetcode/problems/minimum-absolute-difference-between-elements-with-constraint.h"

#include <climits>
#include <cstdlib>
#include <set>

namespace leetcode {
namespace problem_2817 {

static int solution1(vector<int>& nums, int x) {
  const int n = static_cast<int>(nums.size());

  std::set<int> seen;  // contains nums[k] for k + x <= current index
  int best = INT_MAX;
  for (int j = x; j < n; ++j) {
    seen.insert(nums[j - x]);  // nums[j-x] is now at distance >= x from j
    auto it = seen.lower_bound(nums[j]);
    if (it != seen.end()) {
      best = std::min(best, std::abs(*it - nums[j]));
    }
    if (it != seen.begin()) {
      --it;
      best = std::min(best, std::abs(*it - nums[j]));
    }
  }
  return best;
}

MinimumAbsoluteDifferenceBetweenElementsWithConstraintSolution::MinimumAbsoluteDifferenceBetweenElementsWithConstraintSolution() {
  setMetaInfo({
      .id = 2817,
      .title = "Minimum Absolute Difference Between Elements With Constraint",
      .url = "https://leetcode.com/problems/minimum-absolute-difference-between-elements-with-constraint"
  });
  registerStrategy({.name = "Sorted Set Sliding Window",
                    .expected = "Accepted",
                    .time_complexity = "O(n log n)",
                    .space_complexity = "O(n)",
                    .tags = {"Array", "Binary Search", "Ordered Set"}},
                   solution1);
}

int MinimumAbsoluteDifferenceBetweenElementsWithConstraintSolution::minAbsoluteDifference(vector<int>& nums, int x) {
  return getSolution()(nums, x);
}

}  // namespace problem_2817
}  // namespace leetcode
