#include <gtest/gtest.h>

#include "leetcode/problems/range-sum-query-immutable.h"

using leetcode::problem_303::RangeSumQueryImmutable;

class RangeSumQueryImmutableTest : public ::testing::TestWithParam<int> {
 protected:
  void SetUp() override {}
};

TEST_P(RangeSumQueryImmutableTest, Example1) {
  std::vector<int> nums{-2, 0, 3, -5, 2, -1};
  RangeSumQueryImmutable numArray(nums);
  EXPECT_EQ(numArray.sumRange(0, 2), 1);
  EXPECT_EQ(numArray.sumRange(2, 5), -1);
  EXPECT_EQ(numArray.sumRange(0, 5), -3);
}

INSTANTIATE_TEST_SUITE_P(RangeSumQueryImmutableTestSuite,
                         RangeSumQueryImmutableTest,
                         ::testing::Values(0));
