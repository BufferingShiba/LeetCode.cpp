#include "leetcode/problems/maximum-product-of-three-elements-after-one-replacement.h"

#include <algorithm>
#include <cstdlib>

namespace leetcode {
namespace problem_3732 {

namespace {

long long maxProductImpl(std::vector<int>& nums) {
  const int n = static_cast<int>(nums.size());
  auto v = nums;
  std::sort(v.begin(), v.end());

  const long long M = 100000LL;

  // Global maximum product of three (no replacement inside the triple).
  // Only relevant when n >= 4 (replaced element can sit outside the triple).
  long long candidate_b = LLONG_MIN;
  if (n >= 4) {
    long long cand1 = static_cast<long long>(v[n - 1]) * v[n - 2] * v[n - 3];
    long long cand2 = static_cast<long long>(v[0]) * v[1] * v[n - 1];
    candidate_b = std::max(cand1, cand2);
  }

  // Replacement element inside the triple: result = M * |a * b| where a,b are
  // two distinct non-replaced elements. Optimal pair = top two absolute values.
  long long va1 = 0, va2 = 0;  // largest and second largest absolute values
  for (int val : v) {
    long long av = std::llabs(static_cast<long long>(val));
    if (av >= va1) {
      va2 = va1;
      va1 = av;
    } else if (av > va2) {
      va2 = av;
    }
  }
  long long candidate_a = M * va1 * va2;

  if (n == 3) {
    return candidate_a;
  }
  return std::max(candidate_a, candidate_b);
}

}  // namespace

MaximumProductOfThreeElementsAfterOneReplacementSolution::
    MaximumProductOfThreeElementsAfterOneReplacementSolution() {
  setMetaInfo({.id = 3732,
               .title = "Maximum Product of Three Elements After One Replacement",
               .url = "https://leetcode.com/problems/maximum-product-of-three-elements-after-one-replacement/"});
  registerStrategy({.name = "SortAndCandidates",
                    .expected = "Accepted",
                    .time_complexity = "O(n log n)",
                    .space_complexity = "O(n)",
                    .tags = {"Array", "Math", "Greedy", "Sorting"},
                    .notes = "Replaced value can pick sign freely (+/-1e5); if it lies inside the triple,"
                             "best = M * (top-two absolute values product). If it lies outside (only when n>=4),"
                             "best = global max triple product."},
                   maxProductImpl);
}

long long MaximumProductOfThreeElementsAfterOneReplacementSolution::maxProduct(
    std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace problem_3732
}  // namespace leetcode
