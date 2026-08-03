#include "leetcode/problems/maximum-strong-pair-xor-i.h"

#include <algorithm>
#include <cstdlib>

namespace leetcode {
namespace problem_2932 {

namespace {

int maximumStrongPairXorImpl(std::vector<int>& nums) {
  const int n = static_cast<int>(nums.size());
  int best = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = i; j < n; ++j) {
      int x = nums[i];
      int y = nums[j];
      int lo = std::min(x, y);
      if (std::abs(x - y) <= lo) {
        best = std::max(best, x ^ y);
      }
    }
  }
  return best;
}

}  // namespace

MaximumStrongPairXorISolution::MaximumStrongPairXorISolution() {
  setMetaInfo({.id = 2932,
               .title = "Maximum Strong Pair XOR I",
               .url = "https://leetcode.com/problems/maximum-strong-pair-xor-i/"});
  registerStrategy({.name = "brute_force",
                    .expected = "Accepted",
                    .time_complexity = "O(n^2)",
                    .space_complexity = "O(1)",
                    .tags = {"Array", "Bit Manipulation"}},
                   maximumStrongPairXorImpl);
}

int MaximumStrongPairXorISolution::maximumStrongPairXor(std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace problem_2932
}  // namespace leetcode
