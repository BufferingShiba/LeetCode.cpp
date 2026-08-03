#include "leetcode/problems/harshad-number.h"

namespace leetcode {
namespace problem_3099 {

namespace {

int sumOfTheDigitsOfHarshadNumberImpl(int x) {
  int sum = 0;
  int n = x;
  while (n > 0) {
    sum += n % 10;
    n /= 10;
  }
  if (sum == 0 || x % sum != 0) {
    return -1;
  }
  return sum;
}

}  // namespace

HarshadNumberSolution::HarshadNumberSolution() {
  setMetaInfo({3099, "Harshad Number",
               "https://leetcode.com/problems/harshad-number/"});
  registerStrategy(
      {.name = "digit-sum-divisibility",
       .expected = "Accepted",
       .time_complexity = "O(log x)",
       .space_complexity = "O(1)",
       .tags = {"Math"}},
      [](int x) -> int { return sumOfTheDigitsOfHarshadNumberImpl(x); });
}

int HarshadNumberSolution::sumOfTheDigitsOfHarshadNumber(int x) {
  return getSolution()(x);
}

}  // namespace problem_3099
}  // namespace leetcode
