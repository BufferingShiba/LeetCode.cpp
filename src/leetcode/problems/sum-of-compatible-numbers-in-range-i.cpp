#include "leetcode/problems/sum-of-compatible-numbers-in-range-i.h"

namespace leetcode::problem_3954 {

namespace {

int sumOfGoodIntegersImpl(int n, int k) {
  int sum = 0;
  const int low = n - k;
  const int high = n + k;
  for (int x = std::max(1, low); x <= high; ++x) {
    if ((n & x) == 0) {
      sum += x;
    }
  }
  return sum;
}

}  // namespace

SumOfCompatibleNumbersInRangeISolution::SumOfCompatibleNumbersInRangeISolution() {
  this->setMetaInfo({.id = 3954,
                     .title = "Sum of Compatible Numbers in Range I",
                     .url = "https://leetcode.com/problems/sum-of-compatible-numbers-in-range-i/"});
  this->registerStrategy(
      {.name = "brute-force-range",
       .expected = "Accepted",
       .time_complexity = "O(k)",
       .space_complexity = "O(1)",
       .tags = {"Enumeration", "Bit Manipulation"},
       .notes = "Enumerate x in [max(1,n-k), n+k] and check (n & x) == 0."},
      sumOfGoodIntegersImpl);
}

int SumOfCompatibleNumbersInRangeISolution::sumOfGoodIntegers(int n, int k) {
  return this->getSolution()(n, k);
}

}  // namespace leetcode::problem_3954
