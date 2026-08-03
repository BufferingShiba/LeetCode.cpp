#include "leetcode/problems/height-checker.h"

#include <vector>

namespace leetcode::problem_1051 {

namespace {

int heightCheckerImpl(std::vector<int>& heights) {
  int count[101] = {0};
  for (int h : heights) {
    ++count[h];
  }

  int mismatch = 0;
  int cur = 1;  // current expected height (1..100)
  for (int h : heights) {
    while (cur <= 100 && count[cur] == 0) {
      ++cur;
    }
    if (h != cur) {
      ++mismatch;
    }
    --count[cur];
  }

  return mismatch;
}

}  // namespace

HeightCheckerSolution::HeightCheckerSolution() {
  setMetaInfo({.id = 1051,
               .title = "Height Checker",
               .url = "https://leetcode.com/problems/height-checker/"});

  registerStrategy(
      {.name = "Counting Sort",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"Array", "Sorting", "Counting Sort"}},
      heightCheckerImpl);

  setDefaultStrategy();
}

int HeightCheckerSolution::heightChecker(std::vector<int>& heights) {
  return getSolution()(heights);
}

}  // namespace leetcode::problem_1051
