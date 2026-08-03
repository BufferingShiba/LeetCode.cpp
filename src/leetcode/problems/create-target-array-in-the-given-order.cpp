#include "leetcode/problems/create-target-array-in-the-given-order.h"

#include <vector>

namespace leetcode {
namespace problem_1389 {
namespace {

std::vector<int> createTargetArrayImpl(std::vector<int>& nums,
                                       std::vector<int>& index) {
  std::vector<int> target;
  target.reserve(nums.size());
  for (size_t i = 0; i < nums.size(); ++i) {
    target.insert(target.begin() + index[i], nums[i]);
  }
  return target;
}

}  // namespace

CreateTargetArrayInTheGivenOrderSolution::
    CreateTargetArrayInTheGivenOrderSolution() {
  setMetaInfo({.id = 1389,
               .title = "Create Target Array in the Given Order",
               .url = "https://leetcode.com/problems/create-target-array-in-the-given-order/"});
  registerStrategy({
                       .name = "SimulateInsert",
                       .expected = "Accepted",
                       .time_complexity = "O(n^2)",
                       .space_complexity = "O(n)",
                       .tags = {"Array", "Simulation"},
                   },
                   createTargetArrayImpl);
}

std::vector<int>
CreateTargetArrayInTheGivenOrderSolution::createTargetArray(
    std::vector<int>& nums, std::vector<int>& index) {
  return getSolution()(nums, index);
}

}  // namespace problem_1389
}  // namespace leetcode
