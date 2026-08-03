
#include "leetcode/problems/find-the-value-of-the-partition.h"

#include "gtest/gtest.h"

namespace leetcode {
namespace problem_2740 {

class FindTheValueOfThePartitionTest : public ::testing::TestWithParam<string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  FindTheValueOfThePartitionSolution solution;
};

TEST_P(FindTheValueOfThePartitionTest, Example1) {
  vector<int> nums = {1, 3, 2, 4};
  EXPECT_EQ(1, solution.findValueOfPartition(nums));
}

TEST_P(FindTheValueOfThePartitionTest, Example2) {
  vector<int> nums = {100, 1, 10};
  EXPECT_EQ(9, solution.findValueOfPartition(nums));
}

TEST_P(FindTheValueOfThePartitionTest, SelfAuthoredTwoEqualElements) {
  vector<int> nums = {5, 5};
  EXPECT_EQ(0, solution.findValueOfPartition(nums));
}

TEST_P(FindTheValueOfThePartitionTest, SelfAuthoredAlreadySorted) {
  vector<int> nums = {1, 2, 3, 4, 5};
  EXPECT_EQ(1, solution.findValueOfPartition(nums));
}

TEST_P(FindTheValueOfThePartitionTest, SelfAuthoredLargeGap) {
  vector<int> nums = {1, 1000000000};
  EXPECT_EQ(999999999, solution.findValueOfPartition(nums));
}

INSTANTIATE_TEST_SUITE_P(
    LeetCode, FindTheValueOfThePartitionTest,
    ::testing::ValuesIn(FindTheValueOfThePartitionSolution().getStrategyNames()));

}  // namespace problem_2740
}  // namespace leetcode
