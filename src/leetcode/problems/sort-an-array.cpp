#include "leetcode/problems/sort-an-array.h"

namespace leetcode {
namespace problem_912 {

namespace {

constexpr int kOffset = 50000;
constexpr int kCountSize = 100001;

// Counting sort: O(n + k) time, O(k) space where k = 100001 is the fixed
// value range of nums[i] in [-50000, 50000]. This is faster than the required
// O(n log n) and is stable.
std::vector<int> sortArrayImpl(std::vector<int>& nums) {
  std::vector<int> count(kCountSize, 0);
  for (int v : nums) {
    ++count[v + kOffset];
  }
  std::vector<int> result;
  result.reserve(nums.size());
  for (int i = 0; i < kCountSize; ++i) {
    for (int j = 0; j < count[i]; ++j) {
      result.push_back(i - kOffset);
    }
  }
  return result;
}

}  // namespace

SortAnArraySolution::SortAnArraySolution() {
  setMetaInfo({.id = 912,
               .title = "Sort an Array",
               .url = "https://leetcode.com/problems/sort-an-array/"});
  registerStrategy(
      {.name = "CountingSort",
       .expected = "Accepted",
       .time_complexity = "O(n + k)",
       .space_complexity = "O(k)",
       .tags = {"Array", "Sorting", "Counting Sort"},
       .notes =
           "Because nums[i] is bounded in [-50000, 50000], counting sort runs "
           "in O(n + 100001), strictly better than the required O(n log n)."},
      sortArrayImpl);
}

std::vector<int> SortAnArraySolution::sortArray(std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace problem_912
}  // namespace leetcode
