#include <gtest/gtest.h>

#include <vector>

#include "leetcode/problems/maximum-fruits-harvested-after-at-most-k-steps.h"

namespace leetcode {
namespace problem_2106 {

class MaximumFruitsHarvestedAfterAtMostKStepsTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  MaximumFruitsHarvestedAfterAtMostKStepsSolution solution_;
};

TEST_P(MaximumFruitsHarvestedAfterAtMostKStepsTest, Example1) {
  std::vector<std::vector<int>> fruits{{2, 8}, {6, 3}, {8, 6}};
  EXPECT_EQ(solution_.maxTotalFruits(fruits, 5, 4), 9);
}

TEST_P(MaximumFruitsHarvestedAfterAtMostKStepsTest, Example2) {
  std::vector<std::vector<int>> fruits{
      {0, 9}, {4, 1}, {5, 7}, {6, 2}, {7, 4}, {10, 9}};
  EXPECT_EQ(solution_.maxTotalFruits(fruits, 5, 4), 14);
}

TEST_P(MaximumFruitsHarvestedAfterAtMostKStepsTest, Example3) {
  std::vector<std::vector<int>> fruits{{0, 3}, {6, 4}, {8, 5}};
  EXPECT_EQ(solution_.maxTotalFruits(fruits, 3, 2), 0);
}

TEST_P(MaximumFruitsHarvestedAfterAtMostKStepsTest, SelfAuthoredStartAtFruitZeroSteps) {
  std::vector<std::vector<int>> fruits{{5, 10}, {6, 5}};
  EXPECT_EQ(solution_.maxTotalFruits(fruits, 5, 0), 10);
}

TEST_P(MaximumFruitsHarvestedAfterAtMostKStepsTest, SelfAuthoredSingleFruitWithinK) {
  std::vector<std::vector<int>> fruits{{1, 7}};
  EXPECT_EQ(solution_.maxTotalFruits(fruits, 2, 2), 7);
}

INSTANTIATE_TEST_SUITE_P(
    MaximumFruitsHarvestedAfterAtMostKStepsTestSuite,
    MaximumFruitsHarvestedAfterAtMostKStepsTest,
    ::testing::ValuesIn(
        MaximumFruitsHarvestedAfterAtMostKStepsSolution().getStrategyNames()));

}  // namespace problem_2106
}  // namespace leetcode
