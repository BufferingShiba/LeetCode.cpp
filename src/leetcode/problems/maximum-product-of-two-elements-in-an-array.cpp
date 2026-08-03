#include "leetcode/problems/maximum-product-of-two-elements-in-an-array.h"

namespace leetcode {
namespace problem_1464 {

namespace {

int maxProductImpl(std::vector<int>& nums) {
  int first = 0;
  int second = 0;
  for (int x : nums) {
    if (x > first) {
      second = first;
      first = x;
    } else if (x > second) {
      second = x;
    }
  }
  return (first - 1) * (second - 1);
}

}  // namespace

MaximumProductOfTwoElementsInAnArray::MaximumProductOfTwoElementsInAnArray() {
  setMetaInfo({.id = 1464,
               .title = "Maximum Product of Two Elements in an Array",
               .url = "https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array/"});
  registerStrategy(
      {.name = "SinglePass",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"Array"}},
      maxProductImpl);
}

int MaximumProductOfTwoElementsInAnArray::maxProduct(std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace problem_1464
}  // namespace leetcode
