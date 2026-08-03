#include "leetcode/problems/find-the-array-concatenation-value.h"

#include <string>
#include <vector>

namespace leetcode {
namespace problem_2562 {
namespace {

long long findTheArrayConcValImpl(std::vector<int>& nums) {
  long long result = 0;
  int i = 0;
  int j = static_cast<int>(nums.size()) - 1;
  while (i < j) {
    long long first = nums[i];
    long long last = nums[j];
    // Count digits of last.
    long long multiplier = 10;
    long long tmp = last;
    while (tmp >= 10) {
      multiplier *= 10;
      tmp /= 10;
    }
    result += first * multiplier + last;
    ++i;
    --j;
  }
  if (i == j) {
    result += nums[i];
  }
  return result;
}

}  // namespace

FindTheArrayConcatenationValueSolution::FindTheArrayConcatenationValueSolution() {
  setMetaInfo({.id = 2562,
               .title = "Find the Array Concatenation Value",
               .url = "https://leetcode.com/problems/find-the-array-concatenation-value/"});
  registerStrategy(
      {.name = "TwoPointers",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"Array", "Two Pointers", "Simulation"}},
      findTheArrayConcValImpl);
}

long long FindTheArrayConcatenationValueSolution::findTheArrayConcVal(
    std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace problem_2562
}  // namespace leetcode
