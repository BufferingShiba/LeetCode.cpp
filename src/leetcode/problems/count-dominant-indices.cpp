#include "leetcode/problems/count-dominant-indices.h"

#include <vector>

namespace leetcode::problem_3833 {

namespace {

int dominantIndicesImpl(std::vector<int>& nums) {
  const int n = static_cast<int>(nums.size());
  int result = 0;
  long long suffix_sum = 0;
  int count = 0;
  for (int i = n - 1; i >= 0; --i) {
    if (count > 0 && static_cast<long long>(nums[i]) * count > suffix_sum) {
      ++result;
    }
    suffix_sum += nums[i];
    ++count;
  }
  return result;
}

}  // namespace

CountDominantIndicesSolution::CountDominantIndicesSolution() {
  setMetaInfo({.id = 3833,
               .title = "Count Dominant Indices",
               .url = "https://leetcode.com/problems/count-dominant-indices/"});
  registerStrategy(
      {"SuffixScan", "Accepted", "O(n)", "O(1)",
       {"Array", "Enumeration"}},
      dominantIndicesImpl);
}

int CountDominantIndicesSolution::dominantIndices(std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace leetcode::problem_3833
