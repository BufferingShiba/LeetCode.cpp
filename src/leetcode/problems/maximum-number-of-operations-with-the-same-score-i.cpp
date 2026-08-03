#include "leetcode/problems/maximum-number-of-operations-with-the-same-score-i.h"

namespace leetcode::problem_3038 {

namespace {

int maxOperationsImpl(std::vector<int>& nums) {
  const int score = nums[0] + nums[1];
  int count = 1;
  for (std::size_t i = 2; i + 1 < nums.size(); i += 2) {
    if (nums[i] + nums[i + 1] != score) {
      break;
    }
    ++count;
  }
  return count;
}

}  // namespace

MaximumNumberOfOperationsWithTheSameScoreISolution::
    MaximumNumberOfOperationsWithTheSameScoreISolution() {
  setMetaInfo({.id = 3038,
               .title = "Maximum Number of Operations With the Same Score I",
               .url = "https://leetcode.com/problems/maximum-number-of-operations-with-the-same-score-i/"});
  registerStrategy({.name = "fixed score scan",
                    .expected = "Accepted",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(1)",
                    .tags = {"Array", "Simulation"}},
                   maxOperationsImpl);
}

int MaximumNumberOfOperationsWithTheSameScoreISolution::maxOperations(
    std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace leetcode::problem_3038
