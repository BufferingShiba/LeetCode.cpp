#include <gtest/gtest.h>

#include "leetcode/problems/maximize-cyclic-partition-score.h"

namespace leetcode {
namespace problem_3743 {

class MaximizeCyclicPartitionScoreTest
    : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  MaximizeCyclicPartitionScoreSolution solution_;
};

TEST_P(MaximizeCyclicPartitionScoreTest, Example1) {
  std::vector<int> nums = {1, 2, 3, 3};
  EXPECT_EQ(solution_.maximumScore(nums, 2), 3);
}

TEST_P(MaximizeCyclicPartitionScoreTest, Example2) {
  std::vector<int> nums = {1, 2, 3, 3};
  EXPECT_EQ(solution_.maximumScore(nums, 1), 2);
}

TEST_P(MaximizeCyclicPartitionScoreTest, Example3) {
  std::vector<int> nums = {1, 2, 3, 3};
  EXPECT_EQ(solution_.maximumScore(nums, 4), 3);
}

TEST_P(MaximizeCyclicPartitionScoreTest, SelfAuthoredAllSameValues) {
  std::vector<int> nums = {4, 4, 4, 4};
  EXPECT_EQ(solution_.maximumScore(nums, 2), 0);
}

TEST_P(MaximizeCyclicPartitionScoreTest, SelfAuthoredSingleElement) {
  std::vector<int> nums = {7};
  EXPECT_EQ(solution_.maximumScore(nums, 1), 0);
}

TEST_P(MaximizeCyclicPartitionScoreTest, SelfAuthoredLargeK) {
  std::vector<int> nums = {1, 10, 2, 9, 3, 8};
  int k = 100;
  EXPECT_EQ(solution_.maximumScore(nums, k), 21);
}

TEST_P(MaximizeCyclicPartitionScoreTest, SelfAuthoredKEqualsN) {
  std::vector<int> nums = {100, 1, 50, 2};
  // sorted = [1,2,50,100], n=4, n/2=2
  // c=1: 100-1=99
  // c=2: (100+50)-(1+2)=150-3=147
  EXPECT_EQ(solution_.maximumScore(nums, 4), 147);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies, MaximizeCyclicPartitionScoreTest,
    testing::ValuesIn(
        MaximizeCyclicPartitionScoreSolution().getStrategyNames()));

}  // namespace problem_3743
}  // namespace leetcode
