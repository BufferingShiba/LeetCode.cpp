#include "leetcode/problems/count-indices-with-opposite-parity.h"

namespace leetcode::problem_3917 {

namespace {
std::vector<int> countOppositeParityImpl(std::vector<int>& nums) {
  int n = static_cast<int>(nums.size());
  std::vector<int> answer(n, 0);
  int oddCount = 0, evenCount = 0;
  for (int i = n - 1; i >= 0; --i) {
    if (nums[i] % 2 == 0) {
      answer[i] = oddCount;
      ++evenCount;
    } else {
      answer[i] = evenCount;
      ++oddCount;
    }
  }
  return answer;
}
}  // namespace

CountIndicesWithOppositeParitySolution::CountIndicesWithOppositeParitySolution() {
  setMetaInfo({.id = 3917,
               .title = "Count Indices With Opposite Parity",
               .url = "https://leetcode.com/problems/count-indices-with-opposite-parity/"});
  registerStrategy({.name = "suffix-count",
                    .expected = "Accepted",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(1)",
                    .tags = {"Array"}},
                   countOppositeParityImpl);
}

std::vector<int> CountIndicesWithOppositeParitySolution::countOppositeParity(
    std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace leetcode::problem_3917
