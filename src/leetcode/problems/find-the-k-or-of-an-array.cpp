#include "leetcode/problems/find-the-k-or-of-an-array.h"

namespace leetcode {
namespace problem_2917 {
namespace {

int findKOrImpl(std::vector<int>& nums, int k) {
  int result = 0;
  const int n = static_cast<int>(nums.size());
  for (int bit = 0; bit < 31; ++bit) {
    int count = 0;
    for (int num : nums) {
      if ((num >> bit) & 1) {
        ++count;
      }
    }
    if (count >= k) {
      result |= (1 << bit);
    }
  }
  (void)n;
  return result;
}

}  // namespace

FindTheKOrOfAnArraySolution::FindTheKOrOfAnArraySolution() {
  setMetaInfo({.id = 2917,
               .title = "Find the K-or of an Array",
               .url = "https://leetcode.com/problems/find-the-k-or-of-an-array/"});
  registerStrategy(
      {.name = "bitwise-count",
       .expected = "Accepted",
       .time_complexity = "O(31 * n)",
       .space_complexity = "O(1)",
       .tags = {"Array", "Bit Manipulation"}},
      findKOrImpl);
}

int FindTheKOrOfAnArraySolution::findKOr(std::vector<int>& nums, int k) {
  return getSolution()(nums, k);
}

}  // namespace problem_2917
}  // namespace leetcode
