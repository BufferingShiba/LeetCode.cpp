#include "leetcode/problems/semi-ordered-permutation.h"

namespace leetcode {
namespace problem_2717 {

namespace {

int semiOrderedPermutation(std::vector<int>& nums) {
  const int n = static_cast<int>(nums.size());
  int p1 = 0;
  int pn = 0;
  for (int i = 0; i < n; ++i) {
    if (nums[i] == 1) p1 = i;
    else if (nums[i] == n) pn = i;
  }
  int ans = p1 + (n - 1 - pn);
  if (p1 > pn) --ans;
  return ans;
}

}  // namespace

SemiOrderedPermutationSolution::SemiOrderedPermutationSolution() {
  setMetaInfo({.id = 2717,
               .title = "Semi-Ordered Permutation",
               .url = "https://leetcode.com/problems/semi-ordered-permutation/"});

  registerStrategy(
      {"GreedySwap", "Accepted", "O(n)", "O(1)", {"Array", "Simulation"}},
      semiOrderedPermutation);
}

}  // namespace problem_2717
}  // namespace leetcode
