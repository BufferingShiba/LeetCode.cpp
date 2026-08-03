#include "leetcode/problems/smallest-even-multiple.h"

namespace leetcode::problem_2413 {

namespace {

int smallestEvenMultipleImpl(int n) {
  return n % 2 == 0 ? n : n * 2;
}

}  // namespace

SmallestEvenMultipleSolution::SmallestEvenMultipleSolution() {
  setMetaInfo({.id = 2413,
               .title = "Smallest Even Multiple",
               .url = "https://leetcode.com/problems/smallest-even-multiple/"});

  registerStrategy(
      {.name = "Mathematical",
       .expected = "Accepted",
       .time_complexity = "O(1)",
       .space_complexity = "O(1)",
       .tags = {"Math", "Number Theory"}},
      smallestEvenMultipleImpl);

  setDefaultStrategy();
}

int SmallestEvenMultipleSolution::smallestEvenMultiple(int n) {
  return getSolution()(n);
}

}  // namespace leetcode::problem_2413
