#include "leetcode/problems/third-maximum-number.h"

#include <climits>
#include <vector>

namespace leetcode::problem_414 {

namespace {

int thirdMaxImpl(std::vector<int>& nums) {
  long first = LONG_MIN;
  long second = LONG_MIN;
  long third = LONG_MIN;

  for (int num : nums) {
    long v = static_cast<long>(num);
    if (v == first || v == second || v == third) {
      continue;
    }
    if (v > first) {
      third = second;
      second = first;
      first = v;
    } else if (v > second) {
      third = second;
      second = v;
    } else if (v > third) {
      third = v;
    }
  }

  return third == LONG_MIN ? static_cast<int>(first) : static_cast<int>(third);
}

}  // namespace

ThirdMaximumNumberSolution::ThirdMaximumNumberSolution() {
  setMetaInfo({.id = 414,
               .title = "Third Maximum Number",
               .url = "https://leetcode.com/problems/third-maximum-number/"});
  registerStrategy({.name = "SinglePassThreeMax",
                    .expected = "Accepted",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(1)",
                    .tags = {"Array", "Sorting"}},
                   thirdMaxImpl);
}

int ThirdMaximumNumberSolution::thirdMax(std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace leetcode::problem_414
