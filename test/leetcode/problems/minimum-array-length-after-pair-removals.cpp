#include <gtest/gtest.h>

#include "leetcode/problems/minimum-array-length-after-pair-removals.h"

using namespace leetcode::problem_2856;

class MinimumArrayLengthAfterPairRemovalsTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  MinimumArrayLengthAfterPairRemovalsSolution solution_;
};

TEST_P(MinimumArrayLengthAfterPairRemovalsTest, Example1) {
  std::vector<int> nums{1, 2, 3, 4};
  EXPECT_EQ(solution_.minLengthAfterRemovals(nums), 0);
}

TEST_P(MinimumArrayLengthAfterPairRemovalsTest, Example2) {
  std::vector<int> nums{1, 1, 2, 2, 3, 3};
  EXPECT_EQ(solution_.minLengthAfterRemovals(nums), 0);
}

TEST_P(MinimumArrayLengthAfterPairRemovalsTest, Example3) {
  std::vector<int> nums{1000000000, 1000000000};
  EXPECT_EQ(solution_.minLengthAfterRemovals(nums), 2);
}

TEST_P(MinimumArrayLengthAfterPairRemovalsTest, Example4) {
  std::vector<int> nums{2, 3, 4, 4, 4};
  EXPECT_EQ(solution_.minLengthAfterRemovals(nums), 1);
}

TEST_P(MinimumArrayLengthAfterPairRemovalsTest, SelfAuthoredSingleElement) {
  std::vector<int> nums{5};
  EXPECT_EQ(solution_.minLengthAfterRemovals(nums), 1);
}

TEST_P(MinimumArrayLengthAfterPairRemovalsTest, SelfAuthoredAllDistinctOdd) {
  std::vector<int> nums{1, 3, 5, 7, 9};
  EXPECT_EQ(solution_.minLengthAfterRemovals(nums), 1);
}

INSTANTIATE_TEST_SUITE_P(
    MinimumArrayLengthAfterPairRemovalsTestSuite,
    MinimumArrayLengthAfterPairRemovalsTest,
    ::testing::ValuesIn(
        MinimumArrayLengthAfterPairRemovalsSolution().getStrategyNames()));
