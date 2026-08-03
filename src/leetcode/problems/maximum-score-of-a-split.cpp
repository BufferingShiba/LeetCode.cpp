#include "leetcode/problems/maximum-score-of-a-split.h"

#include <algorithm>
#include <vector>

namespace leetcode {
namespace problem_3788 {

namespace {

long long maximumScoreImpl(std::vector<int>& nums) {
  const int n = static_cast<int>(nums.size());

  long long total = 0;
  for (int v : nums) {
    total += v;
  }

  // For split index i (0 <= i < n-1):
  //   score(i) = prefixSum(i) - suffixMin(i)
  //            = (total - suffixSum(i)) - suffixMin(i)
  // where suffixSum(i) = sum(nums[i+1 .. n-1])
  // and   suffixMin(i) = min(nums[i+1 .. n-1]).
  // Scan from right to left maintaining suffixSum and suffixMin directly
  // (O(1) extra space, O(n) time).
  long long suffixSum = nums[n - 1];
  long long suffixMin = nums[n - 1];

  const long long kNegInf = std::numeric_limits<long long>::lowest();
  long long best = kNegInf;

  for (int i = n - 2; i >= 0; --i) {
    long long pref = total - suffixSum;
    best = std::max(best, pref - suffixMin);

    suffixSum += nums[i];
    suffixMin = std::min<long long>(suffixMin, nums[i]);
  }

  return best;
}

}  // namespace

MaximumScoreOfASplitSolution::MaximumScoreOfASplitSolution() {
  setMetaInfo({.id = 3788,
               .title = "Maximum Score of a Split",
               .url = "https://leetcode.com/problems/maximum-score-of-a-split/"});
  registerStrategy({.name = "SuffixScan",
                    .expected = "Accepted",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(1)",
                    .tags = {"Array", "Prefix Sum"}},
                   maximumScoreImpl);
}

long long MaximumScoreOfASplitSolution::maximumScore(std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace problem_3788
}  // namespace leetcode
