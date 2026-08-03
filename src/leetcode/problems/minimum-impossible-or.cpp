#include "leetcode/problems/minimum-impossible-or.h"

#include <unordered_set>

namespace leetcode {
namespace problem_2568 {

// If all powers of two 1, 2, 4, ..., 2^k are present in nums, then every
// integer from 1 to 2^(k+1)-1 is expressible (any subset of those bits can
// be combined, and each power of two provides its single bit). The smallest
// inexpressible integer is therefore the smallest power of two 2^i that is
// NOT present in the array.
static int solution1(vector<int>& nums) {
  std::unordered_set<int> seen(nums.begin(), nums.end());
  int x = 1;
  while (seen.count(x) != 0) {
    x <<= 1;
  }
  return x;
}

MinimumImpossibleOrSolution::MinimumImpossibleOrSolution() {
  setMetaInfo({
      .id = 2568,
      .title = "Minimum Impossible OR",
      .url = "https://leetcode.com/problems/minimum-impossible-or"
  });
  registerStrategy(
      {.name = "Hash Set",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(n)",
       .tags = {"Hash Table", "Bit Manipulation"}},
      solution1);
}

int MinimumImpossibleOrSolution::minImpossibleOR(vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace problem_2568
}  // namespace leetcode
