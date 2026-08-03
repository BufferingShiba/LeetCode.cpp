#include "leetcode/problems/count-distinct-numbers-on-board.h"

namespace leetcode::problem_2549 {

static int distinctIntegersImpl(int n) {
  if (n == 1) return 1;
  return n - 1;
}

CountDistinctNumbersOnBoardSolution::CountDistinctNumbersOnBoardSolution() {
  setMetaInfo({.id = 2549,
               .title = "Count Distinct Numbers on Board",
               .url = "https://leetcode.com/problems/count-distinct-numbers-on-board/"});

  registerStrategy(
      {.name = "Math O(1)",
       .expected = "Accepted",
       .time_complexity = "O(1)",
       .space_complexity = "O(1)",
       .tags = {"Math"}},
      distinctIntegersImpl);

  setDefaultStrategy();
}

}  // namespace leetcode::problem_2549
