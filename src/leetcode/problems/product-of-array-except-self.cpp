#include "leetcode/problems/product-of-array-except-self.h"

#include <vector>

namespace leetcode::problem_238 {

namespace {

std::vector<int> productExceptSelfImpl(std::vector<int>& nums) {
  int n = static_cast<int>(nums.size());
  std::vector<int> output(n, 1);

  // prefix product: output[i] = product of nums[0..i-1]
  int prefix = 1;
  for (int i = 0; i < n; ++i) {
    output[i] = prefix;
    prefix *= nums[i];
  }

  // suffix product: multiply product of nums[i+1..n-1] into output[i]
  int suffix = 1;
  for (int i = n - 1; i >= 0; --i) {
    output[i] *= suffix;
    suffix *= nums[i];
  }

  return output;
}

}  // namespace

ProductOfArrayExceptSelfSolution::ProductOfArrayExceptSelfSolution() {
  setMetaInfo({.id = 238,
               .title = "Product of Array Except Self",
               .url = "https://leetcode.com/problems/product-of-array-except-self/"});
  registerStrategy({.name = "PrefixSuffix",
                    .expected = "Accepted",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(1)",
                    .tags = {"Array", "Prefix Sum"}},
                   productExceptSelfImpl);
  setDefaultStrategy();
}

std::vector<int> ProductOfArrayExceptSelfSolution::productExceptSelf(
    std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace leetcode::problem_238
