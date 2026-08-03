#include <gtest/gtest.h>

#include "leetcode/problems/binary-subarrays-with-sum.h"

namespace leetcode::problem_930 {

class BinarySubarraysWithSumTest : public ::testing::TestWithParam<std::string> {
 protected:
  BinarySubarraysWithSumSolution solution;
  void SetUp() override { solution.setStrategy(GetParam()); }
};

TEST_P(BinarySubarraysWithSumTest, Example1) {
  std::vector<int> nums = {1, 0, 1, 0, 1};
  int goal = 2;
  EXPECT_EQ(solution.numSubarraysWithSum(nums, goal), 4);
}

TEST_P(BinarySubarraysWithSumTest, Example2) {
  std::vector<int> nums = {0, 0, 0, 0, 0};
  int goal = 0;
  EXPECT_EQ(solution.numSubarraysWithSum(nums, goal), 15);
}

INSTANTIATE_TEST_SUITE_P(
    AllStrategies,
    BinarySubarraysWithSumTest,
    ::testing::ValuesIn(BinarySubarraysWithSumSolution().getStrategyNames()));

}  // namespace leetcode::problem_930
