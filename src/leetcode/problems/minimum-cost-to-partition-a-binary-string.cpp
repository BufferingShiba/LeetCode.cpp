#include "leetcode/problems/minimum-cost-to-partition-a-binary-string.h"

#include <algorithm>
#include <vector>

namespace leetcode {
namespace problem_3864 {

namespace {

long long segmentCost(int length, int sensitive, int encCost, int flatCost) {
  if (sensitive == 0) return flatCost;
  return 1LL * length * sensitive * encCost;
}

long long minimumCostDfs(int left, int right, const std::vector<int>& prefix,
                         int encCost, int flatCost) {
  const int length = right - left;
  const int sensitive = prefix[right] - prefix[left];
  const long long direct =
      segmentCost(length, sensitive, encCost, flatCost);

  if (length % 2 == 1) return direct;

  const int middle = left + length / 2;
  const long long split =
      minimumCostDfs(left, middle, prefix, encCost, flatCost) +
      minimumCostDfs(middle, right, prefix, encCost, flatCost);
  return std::min(direct, split);
}

long long minimumCostImpl(std::string s, int encCost, int flatCost) {
  const int n = static_cast<int>(s.size());
  std::vector<int> prefix(n + 1, 0);
  for (int i = 0; i < n; ++i) {
    prefix[i + 1] = prefix[i] + (s[i] == '1');
  }
  return minimumCostDfs(0, n, prefix, encCost, flatCost);
}

}  // namespace

MinimumCostToPartitionABinaryStringSolution::
    MinimumCostToPartitionABinaryStringSolution() {
  setMetaInfo({.id = 3864,
               .title = "Minimum Cost to Partition a Binary String",
               .url = "https://leetcode.com/problems/minimum-cost-to-partition-a-binary-string/"});
  registerStrategy({.name = "DivideAndConquerPrefixSum",
                    .expected = "Accepted",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(n)",
                    .tags = {"Divide and Conquer", "Prefix Sum"}},
                   minimumCostImpl);
}

}  // namespace problem_3864
}  // namespace leetcode
