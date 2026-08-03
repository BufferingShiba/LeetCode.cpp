#include <gtest/gtest.h>

#include "leetcode/problems/check-if-there-is-a-valid-partition-for-the-array.h"

namespace leetcode::problem_2369 {

class CheckIfThereIsAValidPartitionForTheArrayTest : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }
  CheckIfThereIsAValidPartitionForTheArraySolution solution_;
};

TEST_P(CheckIfThereIsAValidPartitionForTheArrayTest, Example1) {
  std::vector<int> nums = {4, 4, 4, 5, 6};
  EXPECT_TRUE(solution_.validPartition(nums));
}

TEST_P(CheckIfThereIsAValidPartitionForTheArrayTest, Example2) {
  std::vector<int> nums = {1, 1, 1, 2};
  EXPECT_FALSE(solution_.validPartition(nums));
}

TEST_P(CheckIfThereIsAValidPartitionForTheArrayTest, SelfAuthored_AllPairs) {
  std::vector<int> nums = {2, 2, 3, 3};
  EXPECT_TRUE(solution_.validPartition(nums));
}

TEST_P(CheckIfThereIsAValidPartitionForTheArrayTest, SelfAuthored_AllTriples) {
  std::vector<int> nums = {5, 5, 5, 1, 2, 3};
  EXPECT_TRUE(solution_.validPartition(nums));
}

TEST_P(CheckIfThereIsAValidPartitionForTheArrayTest, SelfAuthored_SinglePair) {
  std::vector<int> nums = {7, 7};
  EXPECT_TRUE(solution_.validPartition(nums));
}

INSTANTIATE_TEST_SUITE_P(
    AllStrategies,
    CheckIfThereIsAValidPartitionForTheArrayTest,
    testing::ValuesIn(CheckIfThereIsAValidPartitionForTheArraySolution().getStrategyNames()));

}  // namespace leetcode::problem_2369
