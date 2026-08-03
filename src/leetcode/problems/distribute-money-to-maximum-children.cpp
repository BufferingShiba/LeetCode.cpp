#include "leetcode/problems/distribute-money-to-maximum-children.h"

#include <algorithm>

namespace leetcode {
namespace problem_2591 {

namespace {

// Greedy feasibility: can we make exactly `c` children receive exactly 8 dollars
// while satisfying all rules (all money spent, everyone >= 1, nobody == 4)?
bool canDistribute(int money, int children, int c) {
  const int remainingMoney = money - 8 * c;
  const int remainingChildren = children - c;
  if (remainingMoney < 0) return false;
  if (remainingMoney < remainingChildren) return false;  // can't give everyone >= 1
  if (remainingChildren == 0) {
    // Everyone would receive exactly 8; any leftover must go to someone (making
    // them not exactly 8), so this is only valid when there is no leftover.
    return remainingMoney == 0;
  }
  if (remainingChildren == 1) return remainingMoney != 4;  // single leftover must avoid 4
  return true;  // >= 2 remaining children: always avoidable
}

int distMoneyImpl(int money, int children) {
  if (money < children) return -1;  // not even 1 dollar per child
  int best = std::min(children, money / 8);
  for (int c = best; c >= 0; --c) {
    if (canDistribute(money, children, c)) return c;
  }
  return -1;
}

}  // namespace

DistributeMoneyToMaximumChildrenSolution::DistributeMoneyToMaximumChildrenSolution() {
  setMetaInfo({.id = 2591,
               .title = "Distribute Money to Maximum Children",
               .url = "https://leetcode.com/problems/distribute-money-to-maximum-children/"});
  registerStrategy({.name = "greedy-count-8",
                    .expected = "Accepted",
                    .time_complexity = "O(children)",
                    .space_complexity = "O(1)",
                    .tags = {"Math", "Greedy"}},
                   distMoneyImpl);
}

int DistributeMoneyToMaximumChildrenSolution::distMoney(int money, int children) {
  return getSolution()(money, children);
}

}  // namespace problem_2591
}  // namespace leetcode
