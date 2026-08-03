#include "leetcode/problems/sum-of-squares-of-special-elements.h"

namespace leetcode::problem_2778 {

namespace {

int sumOfSquaresImpl(std::vector<int>& nums) {
  const int n = static_cast<int>(nums.size());
  int result = 0;
  for (int i = 1; i <= n; ++i) {
    if (n % i == 0) {
      result += nums[i - 1] * nums[i - 1];
    }
  }
  return result;
}

}  // namespace

SumOfSquaresOfSpecialElementsSolution::SumOfSquaresOfSpecialElementsSolution() {
  setMetaInfo({.id = 2778,
               .title = "Sum of Squares of Special Elements",
               .url = "https://leetcode.com/problems/sum-of-squares-of-special-elements/"});

  registerStrategy(
      {.name = "Enumeration",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"Array", "Enumeration"}},
      sumOfSquaresImpl);
}

int SumOfSquaresOfSpecialElementsSolution::sumOfSquares(
    std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace leetcode::problem_2778
