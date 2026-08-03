#include "leetcode/problems/sum-of-digits-in-base-k.h"

namespace leetcode {
namespace problem_1837 {

namespace {

int sumBaseImpl(int n, int k) {
  int sum = 0;
  while (n > 0) {
    sum += n % k;
    n /= k;
  }
  return sum;
}

}  // namespace

SumOfDigitsInBaseKSolution::SumOfDigitsInBaseKSolution() {
  setMetaInfo({.id = 1837,
               .title = "Sum of Digits in Base K",
               .url = "https://leetcode.com/problems/sum-of-digits-in-base-k/"});
  registerStrategy(
      {.name = "DigitalSumInBaseK",
       .expected = "Accepted",
       .time_complexity = "O(log_k(n))",
       .space_complexity = "O(1)",
       .tags = {"Math"}},
      sumBaseImpl);
}

int SumOfDigitsInBaseKSolution::sumBase(int n, int k) {
  return getSolution()(n, k);
}

}  // namespace problem_1837
}  // namespace leetcode
