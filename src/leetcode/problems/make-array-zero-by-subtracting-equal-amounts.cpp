#include "leetcode/problems/make-array-zero-by-subtracting-equal-amounts.h"

#include <unordered_set>

namespace leetcode {
namespace problem_2357 {

namespace {

int minimumOperationsImpl(std::vector<int>& nums) {
  std::unordered_set<int> seen;
  for (int v : nums) {
    if (v != 0) {
      seen.insert(v);
    }
  }
  return static_cast<int>(seen.size());
}

}  // namespace

MakeArrayZeroBySubtractingEqualAmountsSolution::
    MakeArrayZeroBySubtractingEqualAmountsSolution() {
  setMetaInfo({2357, "Make Array Zero by Subtracting Equal Amounts",
               "https://leetcode.com/problems/make-array-zero-by-subtracting-equal-amounts/"});
  registerStrategy({"HashSetDistinctCount", "Accepted", "O(n)", "O(n)",
                     {"Array", "Hash Table", "Greedy"}},
                    minimumOperationsImpl);
}

int MakeArrayZeroBySubtractingEqualAmountsSolution::minimumOperations(
    std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace problem_2357
}  // namespace leetcode
