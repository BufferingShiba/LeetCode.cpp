#include <unordered_set>
#include <vector>

#include "leetcode/problems/restore-finishing-order.h"

namespace leetcode::problem_3668 {

namespace {

std::vector<int> recoverOrderImpl(std::vector<int>& order, std::vector<int>& friends) {
  std::unordered_set<int> friendSet(friends.begin(), friends.end());
  std::vector<int> result;
  result.reserve(friends.size());
  for (int id : order) {
    if (friendSet.count(id)) {
      result.push_back(id);
    }
  }
  return result;
}

}  // namespace

RestoreFinishingOrderSolution::RestoreFinishingOrderSolution() {
  setMetaInfo({.id = 3668,
               .title = "Restore Finishing Order",
               .url = "https://leetcode.com/problems/restore-finishing-order/"});
  registerStrategy(
      {.name = "HashSet scan",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(k)",
       .tags = {"Array", "Hash Table"}},
      recoverOrderImpl);
}

std::vector<int> RestoreFinishingOrderSolution::recoverOrder(std::vector<int>& order,
                                                             std::vector<int>& friends) {
  return getSolution()(order, friends);
}

}  // namespace leetcode::problem_3668
