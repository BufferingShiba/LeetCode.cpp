#include "leetcode/problems/house-robber-v.h"

#include <algorithm>
#include <vector>

namespace leetcode {
namespace problem_3840 {

namespace {

long long robImpl(std::vector<int>& nums, std::vector<int>& colors) {
  int n = static_cast<int>(nums.size());
  if (n == 0) return 0;

  long long not_robbed = 0;
  long long robbed = nums[0];

  for (int i = 1; i < n; ++i) {
    long long prev_not = not_robbed;
    long long prev_rob = robbed;

    not_robbed = std::max(prev_not, prev_rob);

    if (colors[i] != colors[i - 1]) {
      robbed = nums[i] + std::max(prev_not, prev_rob);
    } else {
      robbed = nums[i] + prev_not;
    }
  }

  return std::max(not_robbed, robbed);
}

}  // anonymous namespace

HouseRobberVSolution::HouseRobberVSolution() {
  setMetaInfo({.id = 3840, .title = "House Robber V",
               .url = "https://leetcode.com/problems/house-robber-v/"});

  registerStrategy(
      {.name = "DP",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"Array", "Dynamic Programming"}},
      robImpl);

  setDefaultStrategy();
}

long long HouseRobberVSolution::rob(std::vector<int>& nums,
                                     std::vector<int>& colors) {
  return getSolution()(nums, colors);
}

}  // namespace problem_3840
}  // namespace leetcode
