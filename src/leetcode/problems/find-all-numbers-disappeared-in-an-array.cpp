#include "leetcode/problems/find-all-numbers-disappeared-in-an-array.h"

namespace leetcode {
namespace problem_448 {
namespace {

// Mark presence by negating the value at index (value - 1).
std::vector<int> findDisappearedNumbersImpl(std::vector<int>& nums) {
  const int n = static_cast<int>(nums.size());
  for (int i = 0; i < n; ++i) {
    int idx = std::abs(nums[i]) - 1;
    if (nums[idx] > 0) {
      nums[idx] = -nums[idx];
    }
  }
  std::vector<int> result;
  for (int i = 0; i < n; ++i) {
    if (nums[i] > 0) {
      result.push_back(i + 1);
    }
  }
  return result;
}

}  // namespace

FindAllNumbersDisappearedInAnArraySolution::
    FindAllNumbersDisappearedInAnArraySolution() {
  setMetaInfo({.id = 448,
               .title = "Find All Numbers Disappeared in an Array",
               .url = "https://leetcode.com/problems/find-all-numbers-"
                      "disappeared-in-an-array/"});

  registerStrategy(
      {.name = "in-place-marking",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"Array", "Hash Table"}},
      findDisappearedNumbersImpl);
}

std::vector<int> FindAllNumbersDisappearedInAnArraySolution::
    findDisappearedNumbers(std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace problem_448
}  // namespace leetcode
