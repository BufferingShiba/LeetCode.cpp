#include "leetcode/problems/running-sum-of-1d-array.h"

#include <vector>

namespace leetcode::problem_1480 {

namespace {

std::vector<int> runningSumImpl(std::vector<int>& nums) {
  std::vector<int> result(nums.size());
  int sum = 0;
  for (std::size_t i = 0; i < nums.size(); ++i) {
    sum += nums[i];
    result[i] = sum;
  }
  return result;
}

}  // namespace

RunningSumOf1dArraySolution::RunningSumOf1dArraySolution() {
  setMetaInfo({.id = 1480,
               .title = "Running Sum of 1d Array",
               .url = "https://leetcode.com/problems/running-sum-of-1d-array/"});
  registerStrategy(
      {"Prefix Sum", "Accepted", "O(n)", "O(1)",
       {"Array", "Prefix Sum"}},
      runningSumImpl);
}

std::vector<int> RunningSumOf1dArraySolution::runningSum(
    std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace leetcode::problem_1480
