#include "leetcode/problems/check-if-point-is-reachable.h"

#include <numeric>

namespace leetcode {
namespace problem_2543 {

namespace {

bool isReachableImpl(int targetX, int targetY) {
  int g = std::gcd(targetX, targetY);
  return (g & (g - 1)) == 0;
}

}  // namespace

CheckIfPointIsReachableSolution::CheckIfPointIsReachableSolution() {
  setMetaInfo({.id = 2543,
               .title = "Check if Point Is Reachable",
               .url = "https://leetcode.com/problems/check-if-point-is-reachable/"});
  registerStrategy(
      {.name = "gcd_power_of_two",
       .expected = "Accepted",
       .time_complexity = "O(log min(X, Y))",
       .space_complexity = "O(1)",
       .tags = {"Math", "Number Theory"}},
      isReachableImpl);
}

bool CheckIfPointIsReachableSolution::isReachable(int targetX, int targetY) {
  return getSolution()(targetX, targetY);
}

}  // namespace problem_2543
}  // namespace leetcode
