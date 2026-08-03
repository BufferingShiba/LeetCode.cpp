#include "leetcode/problems/minimum-score-by-changing-two-elements.h"

#include <algorithm>
#include <vector>

namespace leetcode {
namespace problem_2567 {

static int minimizeSumImpl(std::vector<int>& nums) {
  int n = static_cast<int>(nums.size());
  std::sort(nums.begin(), nums.end());

  // Three cases: ignore two smallest, ignore two largest,
  // ignore one smallest + one largest
  int ans = std::min({nums[n - 1] - nums[2],    // remove two smallest
                      nums[n - 3] - nums[0],    // remove two largest
                      nums[n - 2] - nums[1]});  // remove one of each
  return ans;
}

int MinimumScoreByChangingTwoElementsSolution::minimizeSum(
    std::vector<int>& nums) {
  return getSolution()(nums);
}

MinimumScoreByChangingTwoElementsSolution::
    MinimumScoreByChangingTwoElementsSolution() {
  setMetaInfo({.id = 2567,
               .title = "Minimum Score by Changing Two Elements",
               .url = "https://leetcode.com/problems/minimum-score-by-changing-two-elements/"});
  registerStrategy({.name = "Sorting",
                    .expected = "Accepted",
                    .time_complexity = "O(n log n)",
                    .space_complexity = "O(1)",
                    .tags = {"Array", "Greedy", "Sorting"}},
                   minimizeSumImpl);
}

}  // namespace problem_2567
}  // namespace leetcode
