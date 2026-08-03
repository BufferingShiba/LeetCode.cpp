#include "leetcode/problems/maximum-sum-of-three-numbers-divisible-by-three.h"

#include <algorithm>
#include <limits>
#include <vector>

namespace leetcode {
namespace problem_3780 {
namespace {

// Choose exactly three numbers whose sum is divisible by three, maximizing the
// sum. Strategy: group numbers by remainder mod 3. The valid remainder patterns
// for the triple are (0,0,0), (0,1,2), (1,1,1), (2,2,2). Within each group, keep
// only the top-3 largest values (we never need more than 3 from any group).
// Enumerate the four patterns and take the best achievable sum.
int maximumSumImpl(std::vector<int>& nums) {
  // groups[r] stores the up-to-3 largest numbers with remainder r.
  std::vector<std::vector<int>> groups(3);
  for (int x : nums) {
    int r = x % 3;
    std::vector<int>& g = groups[r];
    g.push_back(x);
    if (g.size() > 3) {
      // Keep top-3 by dropping the current min.
      auto it = std::min_element(g.begin(), g.end());
      g.erase(it);
    }
  }

  const auto sortedTop = [](std::vector<int> g) {
    std::sort(g.rbegin(), g.rend());
    return g;
  };

  std::vector<int> g0 = sortedTop(groups[0]);
  std::vector<int> g1 = sortedTop(groups[1]);
  std::vector<int> g2 = sortedTop(groups[2]);

  int best = 0;  // 0 means "no valid triple".

  const auto consider = [&](int candidate) {
    if (candidate > best) best = candidate;
  };

  // Helper: sum first k elements if available, else -1 (invalid).
  const auto sumTop = [](const std::vector<int>& g, size_t k) -> int {
    if (g.size() < k) return -1;
    int s = 0;
    for (size_t i = 0; i < k; ++i) s += g[i];
    return s;
  };

  // (0,0,0)
  int v000 = sumTop(g0, 3);
  if (v000 >= 0) consider(v000);

  // (0,1,2)
  int a = sumTop(g0, 1);
  int b = sumTop(g1, 1);
  int c = sumTop(g2, 1);
  if (a >= 0 && b >= 0 && c >= 0) consider(a + b + c);

  // (1,1,1)
  int v111 = sumTop(g1, 3);
  if (v111 >= 0) consider(v111);

  // (2,2,2)
  int v222 = sumTop(g2, 3);
  if (v222 >= 0) consider(v222);

  return best;
}

}  // namespace

MaximumSumOfThreeNumbersDivisibleByThreeSolution::
    MaximumSumOfThreeNumbersDivisibleByThreeSolution() {
  setMetaInfo({
      .id = 3780,
      .title = "Maximum Sum of Three Numbers Divisible by Three",
      .url = "https://leetcode.com/problems/maximum-sum-of-three-numbers-divisible-by-three/",
  });
  registerStrategy(
      {
          .name = "GreedyByRemainderGroup",
          .expected = "Accepted",
          .time_complexity = "O(n)",
          .space_complexity = "O(1)",
          .tags = {"Array", "Greedy", "Sorting"},
      },
      maximumSumImpl);
}

int MaximumSumOfThreeNumbersDivisibleByThreeSolution::maximumSum(
    std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace problem_3780
}  // namespace leetcode
