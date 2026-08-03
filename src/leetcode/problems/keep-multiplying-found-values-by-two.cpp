#include "leetcode/problems/keep-multiplying-found-values-by-two.h"

#include <unordered_set>

namespace leetcode {
namespace problem_2154 {

namespace {

int findFinalValueImpl(std::vector<int>& nums, int original) {
  std::unordered_set<int> seen(nums.begin(), nums.end());
  int cur = original;
  while (seen.count(cur)) {
    cur *= 2;
  }
  return cur;
}

}  // namespace

KeepMultiplyingFoundValuesByTwoSolution::KeepMultiplyingFoundValuesByTwoSolution() {
  setMetaInfo({.id = 2154,
               .title = "Keep Multiplying Found Values by Two",
               .url = "https://leetcode.com/problems/keep-multiplying-found-values-by-two/"});

  registerStrategy({.name = "HashSet",
                    .expected = "Accepted",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(n)",
                    .tags = {"Array", "Hash Table"}},
                   findFinalValueImpl);
}

int KeepMultiplyingFoundValuesByTwoSolution::findFinalValue(std::vector<int>& nums,
                                                            int original) {
  return getSolution()(nums, original);
}

}  // namespace problem_2154
}  // namespace leetcode
