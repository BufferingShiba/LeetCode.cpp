#include "leetcode/problems/minimum-absolute-difference-between-two-values.h"

#include <limits>

namespace leetcode {
namespace problem_3880 {

namespace {

int minAbsoluteDifferenceImpl(std::vector<int>& nums) {
  const int n = static_cast<int>(nums.size());
  int lastOne = -1;
  int lastTwo = -1;
  int answer = std::numeric_limits<int>::max();
  for (int i = 0; i < n; ++i) {
    if (nums[i] == 1) {
      if (lastTwo != -1) {
        answer = std::min(answer, std::abs(i - lastTwo));
      }
      lastOne = i;
    } else if (nums[i] == 2) {
      if (lastOne != -1) {
        answer = std::min(answer, std::abs(i - lastOne));
      }
      lastTwo = i;
    }
  }
  return answer == std::numeric_limits<int>::max() ? -1 : answer;
}

}  // namespace

MinimumAbsoluteDifferenceBetweenTwoValuesSolution::
    MinimumAbsoluteDifferenceBetweenTwoValuesSolution() {
  setMetaInfo({.id = 3880,
               .title = "Minimum Absolute Difference Between Two Values",
               .url = "https://leetcode.com/problems/minimum-absolute-difference-between-two-values/"});
  registerStrategy(
      {.name = "single-pass-two-pointers",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"Array", "Enumeration"}},
      minAbsoluteDifferenceImpl);
}

int MinimumAbsoluteDifferenceBetweenTwoValuesSolution::minAbsoluteDifference(
    std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace problem_3880
}  // namespace leetcode
