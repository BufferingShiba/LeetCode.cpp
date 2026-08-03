#include "leetcode/problems/sign-of-the-product-of-an-array.h"

namespace leetcode::problem_1822 {

static int arraySignImpl(std::vector<int>& nums) {
  int sign = 1;
  for (int num : nums) {
    if (num == 0) return 0;
    if (num < 0) sign = -sign;
  }
  return sign;
}

SignOfTheProductOfAnArraySolution::SignOfTheProductOfAnArraySolution() {
  setMetaInfo({.id = 1822, .title = "Sign of the Product of an Array",
               .url = "https://leetcode.com/problems/sign-of-the-product-of-an-array/"});
  registerStrategy(
      {.name = "Track Sign",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"Array", "Math"}},
      arraySignImpl);
}

int SignOfTheProductOfAnArraySolution::arraySign(std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace leetcode::problem_1822
