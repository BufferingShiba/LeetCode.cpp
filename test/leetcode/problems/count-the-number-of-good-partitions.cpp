#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/count-the-number-of-good-partitions.h"

namespace leetcode {
namespace problem_2963 {
namespace {

std::vector<std::string> GetStrategyNames() {
  CountTheNumberOfGoodPartitionsSolution solution;
  return solution.getStrategyNames();
}

}  // namespace

class CountTheNumberOfGoodPartitionsTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override {
    solution_.setStrategy(GetParam());
  }

  CountTheNumberOfGoodPartitionsSolution solution_;
};

TEST_P(CountTheNumberOfGoodPartitionsTest, Example1) {
  std::vector<int> nums = {1, 2, 3, 4};
  EXPECT_EQ(solution_.numberOfGoodPartitions(nums), 8);
}

TEST_P(CountTheNumberOfGoodPartitionsTest, Example2) {
  std::vector<int> nums = {1, 1, 1, 1};
  EXPECT_EQ(solution_.numberOfGoodPartitions(nums), 1);
}

TEST_P(CountTheNumberOfGoodPartitionsTest, Example3) {
  std::vector<int> nums = {1, 2, 1, 3};
  EXPECT_EQ(solution_.numberOfGoodPartitions(nums), 2);
}

TEST_P(CountTheNumberOfGoodPartitionsTest, SelfAuthoredSingleElement) {
  std::vector<int> nums = {42};
  EXPECT_EQ(solution_.numberOfGoodPartitions(nums), 1);
}

TEST_P(CountTheNumberOfGoodPartitionsTest, SelfAuthoredTwoDistinctElements) {
  std::vector<int> nums = {1, 2};
  EXPECT_EQ(solution_.numberOfGoodPartitions(nums), 2);
}

TEST_P(CountTheNumberOfGoodPartitionsTest, SelfAuthoredRepeatedNonAdjacentPair) {
  // last[1]=2, last[2]=1, last[3]=4, last[4]=3 -> blocks 2? Let's compute:
  // blocks = {[0..2], [3..4]} = 2 -> answer 2^(2-1)=2
  std::vector<int> nums = {1, 2, 1, 3, 3};
  EXPECT_EQ(solution_.numberOfGoodPartitions(nums), 2);
}

INSTANTIATE_TEST_SUITE_P(
    CountTheNumberOfGoodPartitionsTestSuites,
    CountTheNumberOfGoodPartitionsTest,
    ::testing::ValuesIn(GetStrategyNames()));

}  // namespace problem_2963
}  // namespace leetcode
