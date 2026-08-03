#include "leetcode/problems/count-partitions-with-even-sum-difference.h"

namespace leetcode::problem_3432 {

namespace {

int countPartitionsImpl(std::vector<int>& nums) {
  int total = 0;
  for (int num : nums) {
    total += num;
  }
  // diff = 2 * leftSum - total; 2*leftSum is always even,
  // so diff is even iff total is even.
  if (total % 2 == 0) {
    return static_cast<int>(nums.size()) - 1;
  }
  return 0;
}

}  // namespace

CountPartitionsWithEvenSumDifferenceSolution::CountPartitionsWithEvenSumDifferenceSolution() {
  setMetaInfo({.id = 3432,
               .title = "Count Partitions with Even Sum Difference",
               .url = "https://leetcode.com/problems/count-partitions-with-even-sum-difference/"});
  registerStrategy({.name = "total_parity",
                    .expected = "Accepted",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(1)",
                    .tags = {"Array", "Math", "Prefix Sum"}},
                   countPartitionsImpl);
}

int CountPartitionsWithEvenSumDifferenceSolution::countPartitions(std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace leetcode::problem_3432
