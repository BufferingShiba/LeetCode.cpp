#include "leetcode/problems/patching-array.h"

namespace leetcode::problem_330 {

namespace {

int minPatchesImpl(std::vector<int>& nums, int n) {
  long long miss = 1;  // smallest number we cannot form
  int patches = 0;
  int i = 0;
  int m = static_cast<int>(nums.size());

  while (miss <= n) {
    if (i < m && nums[i] <= miss) {
      // we can use nums[i] to extend the reachable range
      miss += nums[i];
      ++i;
    } else {
      // patch miss itself to maximize range extension
      miss += miss;
      ++patches;
    }
  }

  return patches;
}

}  // namespace

PatchingArraySolution::PatchingArraySolution() {
  setMetaInfo({.id = 330,
               .title = "Patching Array",
               .url = "https://leetcode.com/problems/patching-array/"});

  registerStrategy(
      {.name = "Greedy",
       .expected = "Accepted",
       .time_complexity = "O(m + log n)",
       .space_complexity = "O(1)",
       .tags = {"Array", "Greedy"}},
      minPatchesImpl);

  setDefaultStrategy();
}

int PatchingArraySolution::minPatches(std::vector<int>& nums, int n) {
  return getSolution()(nums, n);
}

}  // namespace leetcode::problem_330
