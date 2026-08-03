#include "leetcode/problems/minimum-elements-to-add-to-form-a-given-sum.h"

namespace leetcode::problem_1785 {

int minElementsImpl(std::vector<int>& nums, int limit, int goal) {
  long long sum = 0;
  for (int num : nums) {
    sum += num;
  }
  long long diff = static_cast<long long>(goal) - sum;
  if (diff < 0) {
    diff = -diff;
  }
  return static_cast<int>((diff + limit - 1) / limit);
}

MinimumElementsToAddToFormAGivenSumSolution::MinimumElementsToAddToFormAGivenSumSolution() {
  setMetaInfo({1785, "Minimum Elements to Add to Form a Given Sum",
               "https://leetcode.com/problems/minimum-elements-to-add-to-form-a-given-sum/"});
  registerStrategy(
      {"GreedyMath", "Accepted", "O(n)", "O(1)",
       {"Array", "Greedy"},
       "Each added element changes the sum by at most |limit| in magnitude, so the minimum "
       "count is ceil(|goal - sum| / limit)."},
      minElementsImpl);
}

}  // namespace leetcode::problem_1785
