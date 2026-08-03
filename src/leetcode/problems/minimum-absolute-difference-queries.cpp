#include "leetcode/problems/minimum-absolute-difference-queries.h"

#include <algorithm>
#include <climits>

namespace leetcode {
namespace problem_1906 {

static std::vector<int> minDifferenceImpl(std::vector<int>& nums,
                                          std::vector<std::vector<int>>& queries) {
  constexpr int kMaxVal = 100;
  int n = static_cast<int>(nums.size());

  // prefix[i][v] = count of value v in nums[0..i-1]
  std::vector<std::vector<int>> prefix(n + 1, std::vector<int>(kMaxVal + 1, 0));
  for (int i = 0; i < n; ++i) {
    prefix[i + 1] = prefix[i];
    prefix[i + 1][nums[i]]++;
  }

  std::vector<int> ans;
  ans.reserve(queries.size());

  for (const auto& q : queries) {
    int l = q[0], r = q[1];
    int prev = -1;
    int min_diff = INT_MAX;

    for (int v = 1; v <= kMaxVal; ++v) {
      int cnt = prefix[r + 1][v] - prefix[l][v];
      if (cnt > 0) {
        if (prev != -1) {
          min_diff = std::min(min_diff, v - prev);
        }
        prev = v;
      }
    }

    ans.push_back(min_diff == INT_MAX ? -1 : min_diff);
  }

  return ans;
}

MinimumAbsoluteDifferenceQueriesSolution::MinimumAbsoluteDifferenceQueriesSolution() {
  setMetaInfo({.id = 1906,
               .title = "Minimum Absolute Difference Queries",
               .url = "https://leetcode.com/problems/minimum-absolute-difference-queries/"});
  registerStrategy({.name = "PrefixSum",
                    .expected = "Accepted",
                    .time_complexity = "O((N + Q) * V)",
                    .space_complexity = "O(N * V)",
                    .tags = {"Array", "Prefix Sum"}},
                   minDifferenceImpl);
}

std::vector<int> MinimumAbsoluteDifferenceQueriesSolution::minDifference(
    std::vector<int>& nums,
    std::vector<std::vector<int>>& queries) {
  return getSolution()(nums, queries);
}

}  // namespace problem_1906
}  // namespace leetcode
