#include "leetcode/problems/minimum-cost-to-make-two-binary-strings-equal.h"

#include <algorithm>
#include <cstdlib>

namespace leetcode {
namespace problem_3800 {

namespace {

long long minPairCost(long long flipCost, long long swapCost) {
  return std::min(swapCost, 2LL * flipCost);
}

long long minimumCostImpl(std::string s, std::string t, int flipCost,
                          int swapCost, int crossCost) {
  const int n = static_cast<int>(s.size());
  long long a = 0;  // positions where s[i]='0', t[i]='1'
  long long b = 0;  // positions where s[i]='1', t[i]='0'
  for (int i = 0; i < n; ++i) {
    if (s[i] == t[i]) continue;
    if (s[i] == '0') {
      ++a;
    } else {
      ++b;
    }
  }

  const long long fl = flipCost;
  const long long sw = swapCost;
  const long long cr = crossCost;

  const long long m = std::min(a, b);   // natural opposite-difference pairs
  const long long D = std::llabs(a - b); // leftover same-side differences

  long long pairSingleCost = minPairCost(fl, sw);
  long long ans = m * pairSingleCost + D * fl;

  // Converting some of the D leftover same-side differences via cross swap
  // lets them pair up: each such conversion costs crossCost plus one pair
  // clearance, replacing two flips.
  if (cr + pairSingleCost < 2 * fl) {
    long long k = D / 2;
    ans = m * pairSingleCost + k * (cr + pairSingleCost) + (D - 2 * k) * fl;
  }

  return ans;
}

}  // namespace

MinimumCostToMakeTwoBinaryStringsEqualSolution::
    MinimumCostToMakeTwoBinaryStringsEqualSolution() {
  setMetaInfo({.id = 3800,
               .title = "Minimum Cost to Make Two Binary Strings Equal",
               .url = "https://leetcode.com/problems/minimum-cost-to-make-two-"
                      "binary-strings-equal/"});
  registerStrategy(
      {.name = "counting-greedy",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"String", "Greedy", "Math"},
       .notes =
           "Count opposite-difference pairs; use swap for natural pairs and "
           "decide whether cross-swap conversions for leftover same-side "
           "differences are cheaper than flipping."},
      minimumCostImpl);
}

long long MinimumCostToMakeTwoBinaryStringsEqualSolution::minimumCost(
    std::string s, std::string t, int flipCost, int swapCost, int crossCost) {
  return getSolution()(std::move(s), std::move(t), flipCost, swapCost,
                       crossCost);
}

}  // namespace problem_3800
}  // namespace leetcode
