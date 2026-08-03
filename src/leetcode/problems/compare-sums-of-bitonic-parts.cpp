#include "leetcode/problems/compare-sums-of-bitonic-parts.h"

#include <vector>

namespace leetcode {
namespace problem_3909 {
namespace {

long long compareBitonicSumsImpl(std::vector<int>& nums) {
  const int n = static_cast<int>(nums.size());
  int peak = 0;
  while (peak + 1 < n && nums[peak + 1] > nums[peak]) {
    ++peak;
  }

  long long ascSum = 0;
  for (int i = 0; i <= peak; ++i) {
    ascSum += nums[i];
  }

  long long descSum = 0;
  for (int i = peak; i < n; ++i) {
    descSum += nums[i];
  }

  if (ascSum > descSum) return 0;
  if (ascSum < descSum) return 1;
  return -1;
}

}  // namespace

CompareSumsOfBitonicPartsSolution::CompareSumsOfBitonicPartsSolution() {
  setMetaInfo({.id = 3909,
               .title = "Compare Sums of Bitonic Parts",
               .url = "https://leetcode.com/problems/compare-sums-of-bitonic-parts/"});
  registerStrategy({.name = "peak-scan",
                    .expected = "Accepted",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(1)",
                    .tags = {"Array", "Two Pointers"}},
                   compareBitonicSumsImpl);
}

int CompareSumsOfBitonicPartsSolution::compareBitonicSums(std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace problem_3909
}  // namespace leetcode
