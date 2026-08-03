#include "leetcode/problems/optimal-division.h"

#include <string>
#include <vector>

namespace leetcode {
namespace problem_553 {

static std::string optimalDivisionImpl(std::vector<int>& nums) {
  int n = nums.size();
  if (n == 1) {
    return std::to_string(nums[0]);
  }
  if (n == 2) {
    return std::to_string(nums[0]) + "/" + std::to_string(nums[1]);
  }
  std::string result = std::to_string(nums[0]) + "/(" + std::to_string(nums[1]);
  for (int i = 2; i < n; ++i) {
    result += "/" + std::to_string(nums[i]);
  }
  result += ")";
  return result;
}

OptimalDivisionSolution::OptimalDivisionSolution() {
  setMetaInfo({.id = 553, .title = "Optimal Division", .url = "https://leetcode.com/problems/optimal-division/"});
  registerStrategy({
    .name = "math",
    .expected = "Accepted",
    .time_complexity = "O(n)",
    .space_complexity = "O(1)",
    .tags = {"Array", "Math", "Dynamic Programming"}
  }, optimalDivisionImpl);
}

std::string OptimalDivisionSolution::optimalDivision(std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace problem_553
}  // namespace leetcode
