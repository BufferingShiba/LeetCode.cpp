#include "leetcode/problems/count-operations-to-obtain-zero.h"

namespace leetcode {
namespace problem_2169 {
namespace {

int countOperationsImpl(int num1, int num2) {
  int count = 0;
  while (num1 > 0 && num2 > 0) {
    if (num1 < num2) {
      std::swap(num1, num2);
    }
    count += num1 / num2;
    num1 %= num2;
  }
  return count;
}

}  // namespace

CountOperationsToObtainZeroSolution::CountOperationsToObtainZeroSolution() {
  setMetaInfo({.id = 2169,
               .title = "Count Operations to Obtain Zero",
               .url = "https://leetcode.com/problems/count-operations-to-obtain-zero/"});
  registerStrategy(
      {.name = "Euclidean", .expected = "Accepted",
       .time_complexity = "O(log(min(num1, num2)))", .space_complexity = "O(1)",
       .tags = {"Math", "Simulation"}},
      countOperationsImpl);
}

int CountOperationsToObtainZeroSolution::countOperations(int num1, int num2) {
  return getSolution()(num1, num2);
}

}  // namespace problem_2169
}  // namespace leetcode
