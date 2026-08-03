#include "leetcode/problems/sum-of-values-at-indices-with-k-set-bits.h"

namespace leetcode {
namespace problem_2859 {

static int solution1(vector<int>& nums, int k) {
  int sum = 0;
  for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
    int bits = 0;
    int x = i;
    while (x > 0) {
      bits += x & 1;
      x >>= 1;
    }
    if (bits == k) {
      sum += nums[i];
    }
  }
  return sum;
}

SumOfValuesAtIndicesWithKSetBitsSolution::SumOfValuesAtIndicesWithKSetBitsSolution() {
  setMetaInfo({
      .id = 2859,
      .title = "Sum of Values at Indices With K Set Bits",
      .url = "https://leetcode.com/problems/sum-of-values-at-indices-with-k-set-bits"
  });
  registerStrategy({.name = "Brute Force"}, solution1);
}

int SumOfValuesAtIndicesWithKSetBitsSolution::sumIndicesWithKSetBits(vector<int>& nums, int k) {
  return getSolution()(nums, k);
}

}  // namespace problem_2859
}  // namespace leetcode
