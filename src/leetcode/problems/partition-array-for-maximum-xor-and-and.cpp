#include "leetcode/problems/partition-array-for-maximum-xor-and-and.h"

#include <algorithm>
#include <cstdint>

namespace leetcode {
namespace problem_3630 {
namespace {

// Compute max over subset-xors v of mask of (v & P), using linear basis.
long long maxSpanMasked(const std::vector<int>& nums, int mask,
                        long long P) {
  long long basis[30] = {0};
  // Build a linear basis whose pivots are the highest P-bit of each vector.
  for (int i = 0; i < (int)nums.size(); ++i) {
    if (!((mask >> i) & 1)) continue;
    long long cur = nums[i];
    // Reduce by existing pivot vectors (high to low on P-bits).
    for (int b = 29; b >= 0; --b) {
      if (!((P >> b) & 1)) continue;
      if (basis[b] != 0 && ((cur >> b) & 1)) {
        cur ^= basis[b];
      }
    }
    // Insert at the highest remaining P-bit set in cur.
    for (int b = 29; b >= 0; --b) {
      if (!((P >> b) & 1)) continue;
      if ((cur >> b) & 1) {
        basis[b] = cur;
        break;
      }
    }
  }
  // Greedy maximize the restricted value, comparing only P-bits.
  long long res = 0;
  for (int b = 29; b >= 0; --b) {
    if (!((P >> b) & 1)) continue;
    if (basis[b] != 0) {
      long long cand = res ^ basis[b];
      if ((cand & P) > (res & P)) {
        res = cand;
      }
    }
  }
  return res & P;
}

}  // namespace

// Strategy 1: enumerate middle set B, maximize via linear basis partition.
static long long maximizeXorAndXorImpl(std::vector<int>& nums) {
  int n = (int)nums.size();
  int full = (1 << n);

  std::vector<long long> xmask(full, 0);   // XOR of elements in mask
  std::vector<long long> andMask(full, 0); // AND of elements in mask

  // Compute XOR and AND for all masks via lsb.
  xmask[0] = 0;
  for (int mask = 1; mask < full; ++mask) {
    int lb = mask & (-mask);
    int i = __builtin_ctz(mask);
    int prev = mask ^ lb;
    xmask[mask] = xmask[prev] ^ (long long)nums[i];
  }
  for (int mask = 1; mask < full; ++mask) {
    int lb = mask & (-mask);
    int i = __builtin_ctz(mask);
    int prev = mask ^ lb;
    if (prev == 0) {
      andMask[mask] = nums[i];
    } else {
      andMask[mask] = andMask[prev] & nums[i];
    }
  }

  long long best = 0;
  for (int bmask = 0; bmask < full; ++bmask) {
    int rmask = full - 1 - bmask;
    long long T = xmask[rmask];
    long long P = (~T) & ((1LL << 30) - 1);
    long long maxV = maxSpanMasked(nums, rmask, P);
    long long bestXC = T + 2 * maxV;
    long long cand = andMask[bmask] + bestXC;
    if (cand > best) best = cand;
  }
  return best;
}

PartitionArrayForMaximumXorAndAndSolution::
    PartitionArrayForMaximumXorAndAndSolution() {
  setMetaInfo({.id = 3630,
               .title =
                   "Partition Array for Maximum XOR and AND",
               .url = "https://leetcode.com/problems/partition-array-for-"
                      "maximum-xor-and-and/"});
  SolutionBase<Func>::StrategyMetadata meta{
      .name = "LinearBasisEnumeration",
      .expected = "Accepted",
      .time_complexity = "O(n * 2^n)",
      .space_complexity = "O(2^n)",
      .tags = {"Array", "Math", "Greedy", "Bit Manipulation",
               "Enumeration"}};
  registerStrategy(meta, maximizeXorAndXorImpl);
}

long long PartitionArrayForMaximumXorAndAndSolution::maximizeXorAndXor(
    std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace problem_3630
}  // namespace leetcode
