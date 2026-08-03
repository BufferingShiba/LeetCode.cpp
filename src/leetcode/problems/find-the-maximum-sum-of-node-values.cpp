#include "leetcode/problems/find-the-maximum-sum-of-node-values.h"

#include <algorithm>

namespace leetcode {
namespace problem_3068 {

namespace {

long long maximumValueSumImpl(std::vector<int>& nums, int k,
                              std::vector<std::vector<int>>& /*edges*/) {
  long long total = 0;
  long long pos_sum = 0;
  int pos_cnt = 0;
  long long min_pos = 0;
  bool has_pos = false;

  long long max_nonpos = 0;
  bool has_nonpos = false;

  for (int x : nums) {
    total += x;
    long long nx = static_cast<long long>(x) ^ k;
    long long delta = nx - static_cast<long long>(x);
    if (delta > 0) {
      pos_sum += delta;
      ++pos_cnt;
      if (!has_pos || delta < min_pos) {
        min_pos = delta;
        has_pos = true;
      }
    } else {
      // delta <= 0
      if (!has_nonpos || delta > max_nonpos) {
        max_nonpos = delta;
        has_nonpos = true;
      }
    }
  }

  if (pos_cnt % 2 == 0) {
    return total + pos_sum;
  }

  // pos_cnt is odd: either drop the smallest positive, or add the best non-positive
  long long ans = total + pos_sum - min_pos;  // drop smallest positive
  if (has_nonpos) {
    ans = std::max(ans, total + pos_sum + max_nonpos);  // add best non-positive
  }
  return ans;
}

}  // namespace

FindTheMaximumSumOfNodeValuesSolution::FindTheMaximumSumOfNodeValuesSolution() {
  setMetaInfo({.id = 3068,
               .title = "Find the Maximum Sum of Node Values",
               .url = "https://leetcode.com/problems/find-the-maximum-sum-of-node-values/"});
  registerStrategy({.name = "greedy-even-subset",
                    .expected = "Accepted",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(1)",
                    .tags = {"Array", "Greedy", "Tree", "Bit Manipulation", "Sorting"}},
                   maximumValueSumImpl);
}

long long FindTheMaximumSumOfNodeValuesSolution::maximumValueSum(
    std::vector<int>& nums, int k, std::vector<std::vector<int>>& edges) {
  return getSolution()(nums, k, edges);
}

}  // namespace problem_3068
}  // namespace leetcode
