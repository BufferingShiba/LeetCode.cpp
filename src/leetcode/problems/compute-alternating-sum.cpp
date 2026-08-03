#include "leetcode/problems/compute-alternating-sum.h"

namespace leetcode {
namespace problem_3701 {

namespace {

int alternatingSumImpl(std::vector<int>& nums) {
  int sum = 0;
  for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
    if (i % 2 == 0) {
      sum += nums[i];
    } else {
      sum -= nums[i];
    }
  }
  return sum;
}

}  // namespace

ComputeAlternatingSumSolution::ComputeAlternatingSumSolution() {
  setMetaInfo({.id = 3701,
               .title = "Compute Alternating Sum",
               .url = "https://leetcode.com/problems/compute-alternating-sum/"});
  registerStrategy({.name = "Simulation",
                    .expected = "Accepted",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(1)",
                    .tags = {"Array", "Simulation"}},
                   alternatingSumImpl);
}

int ComputeAlternatingSumSolution::alternatingSum(std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace problem_3701
}  // namespace leetcode
