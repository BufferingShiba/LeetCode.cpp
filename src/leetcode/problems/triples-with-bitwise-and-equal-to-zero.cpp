#include "leetcode/problems/triples-with-bitwise-and-equal-to-zero.h"

#include <array>

namespace leetcode {
namespace problem_982 {
namespace {

constexpr int kMaskSize = 1 << 16;
constexpr int kFull = kMaskSize - 1;

int countTripletsImpl(std::vector<int>& nums) {
  const int n = static_cast<int>(nums.size());

  // sub[mask] = number of elements x in nums such that x is a submask of mask.
  std::array<int, kMaskSize> sub{};
  for (int x : nums) {
    ++sub[x];
  }
  // SOS DP (Zeta transform over subsets)
  for (int b = 0; b < 16; ++b) {
    for (int mask = 0; mask < kMaskSize; ++mask) {
      if ((mask & (1 << b)) != 0) {
        sub[mask] += sub[mask ^ (1 << b)];
      }
    }
  }

  // Count frequencies of pairwise AND values among all ordered pairs (i, j).
  std::array<int, kMaskSize> pairFreq{};
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      ++pairFreq[nums[i] & nums[j]];
    }
  }

  long long ans = 0;
  for (int v = 0; v < kMaskSize; ++v) {
    if (pairFreq[v] == 0) continue;
    // Need third element c such that (v & c) == 0, i.e. c is a submask of (~v)&full.
    int c = kFull ^ v;
    ans += static_cast<long long>(pairFreq[v]) * sub[c];
  }
  return static_cast<int>(ans);
}

}  // namespace

TriplesWithBitwiseAndEqualToZeroSolution::TriplesWithBitwiseAndEqualToZeroSolution() {
  setMetaInfo({.id = 982,
               .title = "Triples with Bitwise AND Equal To Zero",
               .url = "https://leetcode.com/problems/triples-with-bitwise-and-equal-to-zero/"});
  registerStrategy({"SOSDpPairwiseAnd", "Accepted", "O(n^2 + 16 * 2^16)",
                    "O(2^16)", {"Array", "Hash Table", "Bit Manipulation"}},
                   countTripletsImpl);
}

int TriplesWithBitwiseAndEqualToZeroSolution::countTriplets(std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace problem_982
}  // namespace leetcode
