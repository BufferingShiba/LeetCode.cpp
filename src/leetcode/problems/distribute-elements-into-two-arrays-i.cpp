#include "leetcode/problems/distribute-elements-into-two-arrays-i.h"

namespace leetcode {
namespace problem_3069 {

namespace {

std::vector<int> resultArrayImpl(std::vector<int>& nums) {
  std::vector<int> arr1, arr2;
  arr1.push_back(nums[0]);
  arr2.push_back(nums[1]);
  for (size_t i = 2; i < nums.size(); ++i) {
    if (arr1.back() > arr2.back()) {
      arr1.push_back(nums[i]);
    } else {
      arr2.push_back(nums[i]);
    }
  }
  arr1.insert(arr1.end(), arr2.begin(), arr2.end());
  return arr1;
}

}  // namespace

DistributeElementsIntoTwoArraysISolution::DistributeElementsIntoTwoArraysISolution() {
  setMetaInfo({.id = 3069,
               .title = "Distribute Elements Into Two Arrays I",
               .url = "https://leetcode.com/problems/distribute-elements-into-two-arrays-i/"});
  registerStrategy(
      {.name = "Simulation",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(n)",
       .tags = {"Array", "Simulation"}},
      resultArrayImpl);
}

std::vector<int> DistributeElementsIntoTwoArraysISolution::resultArray(
    std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace problem_3069
}  // namespace leetcode
