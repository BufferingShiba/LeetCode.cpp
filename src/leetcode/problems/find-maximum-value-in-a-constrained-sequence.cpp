#include "leetcode/problems/find-maximum-value-in-a-constrained-sequence.h"

#include <algorithm>
#include <climits>
#include <vector>

namespace leetcode {
namespace problem_3796 {

namespace {

int findMaxValImpl(int n, std::vector<std::vector<int>>& restrictions,
                   std::vector<int>& diff) {
  const int INF = 1'000'000'007;
  std::vector<int> upper(n, INF);
  upper[0] = 0;

  for (const auto& r : restrictions) {
    int idx = r[0];
    int maxVal = r[1];
    upper[idx] = std::min(upper[idx], maxVal);
  }

  // left to right
  for (int i = 0; i < n - 1; ++i) {
    upper[i + 1] = std::min(upper[i + 1], upper[i] + diff[i]);
  }

  // right to left
  for (int i = n - 2; i >= 0; --i) {
    upper[i] = std::min(upper[i], upper[i + 1] + diff[i]);
  }

  return *std::max_element(upper.begin(), upper.end());
}

}  // namespace

FindMaximumValueInAConstrainedSequenceSolution::
    FindMaximumValueInAConstrainedSequenceSolution() {
  setMetaInfo({.id = 3796,
               .title = "Find Maximum Value in a Constrained Sequence",
               .url = "https://leetcode.com/problems/find-maximum-value-in-a-constrained-sequence/"});

  registerStrategy(
      {.name = "TwoPassGreedy",
       .expected = "Accepted",
       .time_complexity = "O(n + R)",
       .space_complexity = "O(n)",
       .tags = {"Array", "Greedy"}},
      findMaxValImpl);
}

int FindMaximumValueInAConstrainedSequenceSolution::findMaxVal(
    int n, std::vector<std::vector<int>>& restrictions,
    std::vector<int>& diff) {
  return getSolution()(n, restrictions, diff);
}

}  // namespace problem_3796
}  // namespace leetcode
