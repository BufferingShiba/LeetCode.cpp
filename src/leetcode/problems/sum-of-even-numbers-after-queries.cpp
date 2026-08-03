#include "leetcode/problems/sum-of-even-numbers-after-queries.h"

namespace leetcode {
namespace problem_985 {

namespace {

std::vector<int> sumEvenAfterQueriesImpl(std::vector<int>& nums,
                                         std::vector<std::vector<int>>& queries) {
  int sum = 0;
  for (int num : nums) {
    if (num % 2 == 0) {
      sum += num;
    }
  }
  std::vector<int> ans;
  ans.reserve(queries.size());
  for (const auto& q : queries) {
    int val = q[0];
    int idx = q[1];
    if (nums[idx] % 2 == 0) {
      sum -= nums[idx];
    }
    nums[idx] += val;
    if (nums[idx] % 2 == 0) {
      sum += nums[idx];
    }
    ans.push_back(sum);
  }
  return ans;
}

}  // namespace

SumOfEvenNumbersAfterQueriesSolution::SumOfEvenNumbersAfterQueriesSolution() {
  setMetaInfo({985, "Sum of Even Numbers After Queries",
               "https://leetcode.com/problems/sum-of-even-numbers-after-queries/"});
  registerStrategy(
      {"IncrementalEvenSum", "Accepted", "O(n + q)", "O(1)",
       {"Array", "Simulation"}},
      sumEvenAfterQueriesImpl);
}

std::vector<int> SumOfEvenNumbersAfterQueriesSolution::sumEvenAfterQueries(
    std::vector<int>& nums, std::vector<std::vector<int>>& queries) {
  return getSolution()(nums, queries);
}

}  // namespace problem_985
}  // namespace leetcode
