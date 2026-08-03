#include "leetcode/problems/sum-multiples.h"

namespace {

int sumOfMultiplesImpl(int n) {
  int sum = 0;
  for (int i = 1; i <= n; ++i) {
    if (i % 3 == 0 || i % 5 == 0 || i % 7 == 0) {
      sum += i;
    }
  }
  return sum;
}

}  // namespace

namespace leetcode::problem_2652 {

SumMultiplesSolution::SumMultiplesSolution() {
  setMetaInfo({.id = 2652, .title = "Sum Multiples", .url = "https://leetcode.com/problems/sum-multiples/"});
  registerStrategy({
    .name = "Iterative",
    .expected = "Accepted",
    .time_complexity = "O(n)",
    .space_complexity = "O(1)",
    .tags = {"Math"}
  }, sumOfMultiplesImpl);
}

int SumMultiplesSolution::sumOfMultiples(int n) {
  return getSolution()(n);
}

}  // namespace leetcode::problem_2652
