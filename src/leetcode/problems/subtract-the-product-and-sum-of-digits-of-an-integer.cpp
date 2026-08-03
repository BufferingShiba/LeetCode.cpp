#include "leetcode/problems/subtract-the-product-and-sum-of-digits-of-an-integer.h"

namespace leetcode {
namespace problem_1281 {
namespace {

int subtractProductAndSumImpl(int n) {
  int product = 1;
  int sum = 0;
  while (n > 0) {
    int digit = n % 10;
    product *= digit;
    sum += digit;
    n /= 10;
  }
  return product - sum;
}

}  // namespace

SubtractTheProductAndSumOfDigitsOfAnIntegerSolution::
    SubtractTheProductAndSumOfDigitsOfAnIntegerSolution() {
  setMetaInfo({.id = 1281,
               .title = "Subtract the Product and Sum of Digits of an Integer",
               .url = "https://leetcode.com/problems/"
                      "subtract-the-product-and-sum-of-digits-of-an-integer/"});
  registerStrategy(
      {.name = "direct-digit-iteration",
       .expected = "Accepted",
       .time_complexity = "O(d)",
       .space_complexity = "O(1)",
       .tags = {"Math"}},
      subtractProductAndSumImpl);
}

int SubtractTheProductAndSumOfDigitsOfAnIntegerSolution::
    subtractProductAndSum(int n) {
  return getSolution()(n);
}

}  // namespace problem_1281
}  // namespace leetcode
