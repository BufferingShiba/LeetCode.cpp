#include "leetcode/problems/sum-of-gcd-of-formed-pairs.h"

#include <algorithm>
#include <numeric>
#include <vector>

namespace leetcode {
namespace problem_3867 {

static long long gcdSumImpl(std::vector<int>& nums) {
  const int n = static_cast<int>(nums.size());
  std::vector<int> prefixGcd(n);

  int mx = 0;
  for (int i = 0; i < n; ++i) {
    mx = std::max(mx, nums[i]);
    prefixGcd[i] = std::gcd(nums[i], mx);
  }

  std::sort(prefixGcd.begin(), prefixGcd.end());

  long long sum = 0;
  int half = n / 2;
  for (int i = 0; i < half; ++i) {
    sum += std::gcd(prefixGcd[i], prefixGcd[n - 1 - i]);
  }

  return sum;
}

SumOfGcdOfFormedPairsSolution::SumOfGcdOfFormedPairsSolution() {
  setMetaInfo({.id = 3867,
               .title = "Sum of GCD of Formed Pairs",
               .url = "https://leetcode.com/problems/sum-of-gcd-of-formed-pairs/"});
  registerStrategy(
      {.name = "sort-and-pair",
       .expected = "Accepted",
       .time_complexity = "O(n log n)",
       .space_complexity = "O(n)",
       .tags = {"Array", "Math", "Two Pointers", "Sorting", "Simulation",
                "Number Theory"}},
      gcdSumImpl);
}

long long SumOfGcdOfFormedPairsSolution::gcdSum(std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace problem_3867
}  // namespace leetcode
