#include "leetcode/problems/subsets.h"

namespace leetcode {
namespace problem_78 {

static std::vector<std::vector<int>> subsetsImpl(const std::vector<int>& nums) {
  std::vector<std::vector<int>> result;
  int n = nums.size();
  for (int mask = 0; mask < (1 << n); ++mask) {
    std::vector<int> cur;
    for (int i = 0; i < n; ++i) {
      if (mask & (1 << i)) cur.push_back(nums[i]);
    }
    result.push_back(std::move(cur));
  }
  return result;
}

SubsetsSolution::SubsetsSolution() {
  setMetaInfo({
      .id = 78,
      .title = "Subsets",
      .url = "https://leetcode.com/problems/subsets"
  });
  registerStrategy(
      {.name = "Bitmask Enumeration",
       .expected = "Accepted",
       .time_complexity = "O(2^n * n)",
       .space_complexity = "O(2^n)",
       .tags = {"Array", "Backtracking", "Bit Manipulation"}},
      subsetsImpl);
}

std::vector<std::vector<int>> SubsetsSolution::subsets(const std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace problem_78
}  // namespace leetcode
