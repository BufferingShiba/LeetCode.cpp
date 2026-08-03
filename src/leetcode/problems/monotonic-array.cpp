#include "leetcode/problems/monotonic-array.h"

namespace leetcode {
namespace problem_896 {

namespace {

bool isMonotonicImpl(std::vector<int>& nums) {
  bool increasing = true;
  bool decreasing = true;
  for (std::size_t i = 1; i < nums.size(); ++i) {
    if (nums[i] > nums[i - 1]) {
      decreasing = false;
    } else if (nums[i] < nums[i - 1]) {
      increasing = false;
    }
  }
  return increasing || decreasing;
}

}  // namespace

MonotonicArraySolution::MonotonicArraySolution() {
  setMetaInfo({.id = 896,
               .title = "Monotonic Array",
               .url = "https://leetcode.com/problems/monotonic-array/"});
  registerStrategy(
      {"Single-Pass", "Accepted", "O(n)", "O(1)", {"Array"}},
      isMonotonicImpl);
}

bool MonotonicArraySolution::isMonotonic(std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace problem_896
}  // namespace leetcode
