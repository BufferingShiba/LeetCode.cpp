#include "leetcode/problems/find-the-pivot-integer.h"

#include <cmath>

namespace leetcode {
namespace problem_2485 {

namespace {

int pivotIntegerImpl(int n) {
  int total = n * (n + 1) / 2;
  int root = static_cast<int>(std::sqrt(total));
  if (root * root == total) {
    return root;
  }
  return -1;
}

}  // namespace

FindThePivotIntegerSolution::FindThePivotIntegerSolution() {
  setMetaInfo({.id = 2485,
               .title = "Find the Pivot Integer",
               .url =
                   "https://leetcode.com/problems/find-the-pivot-integer/"});
  registerStrategy(
      {.name = "math",
       .expected = "Accepted",
       .time_complexity = "O(1)",
       .space_complexity = "O(1)",
       .tags = {"Math"}},
      pivotIntegerImpl);
}

int FindThePivotIntegerSolution::pivotInteger(int n) {
  return getSolution()(n);
}

}  // namespace problem_2485
}  // namespace leetcode
