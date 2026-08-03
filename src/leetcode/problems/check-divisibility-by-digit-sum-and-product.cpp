#include "leetcode/problems/check-divisibility-by-digit-sum-and-product.h"

namespace leetcode::problem_3622 {

namespace {

bool checkDivisibilityImpl(int n) {
  long long sum = 0;
  long long product = 1;
  int temp = n;
  while (temp > 0) {
    int digit = temp % 10;
    sum += digit;
    product *= digit;
    temp /= 10;
  }
  long long total = sum + product;
  return total > 0 && n % total == 0;
}

}  // namespace

CheckDivisibilityByDigitSumAndProductSolution::
    CheckDivisibilityByDigitSumAndProductSolution() {
  setMetaInfo({.id = 3622,
               .title = "Check Divisibility by Digit Sum and Product",
               .url = "https://leetcode.com/problems/check-divisibility-by-digit-sum-and-product/"});
  registerStrategy(
      {.name = "digit decomposition",
       .expected = "Accepted",
       .time_complexity = "O(log n)",
       .space_complexity = "O(1)",
       .tags = {"Math"}},
      checkDivisibilityImpl);
}

bool CheckDivisibilityByDigitSumAndProductSolution::checkDivisibility(int n) {
  return getSolution()(n);
}

}  // namespace leetcode::problem_3622
