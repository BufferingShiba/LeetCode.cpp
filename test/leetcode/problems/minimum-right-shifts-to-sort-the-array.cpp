#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/minimum-right-shifts-to-sort-the-array.h"

using leetcode::problem_2855::MinimumRightShiftsToSortTheArraySolution;

class MinimumRightShiftsToSortTheArrayTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  MinimumRightShiftsToSortTheArraySolution solution_;
};

TEST_P(MinimumRightShiftsToSortTheArrayTest, Example1) {
  std::vector<int> nums{3, 4, 5, 1, 2};
  EXPECT_EQ(solution_.minimumRightShifts(nums), 2);
}

TEST_P(MinimumRightShiftsToSortTheArrayTest, Example2) {
  std::vector<int> nums{1, 3, 5};
  EXPECT_EQ(solution_.minimumRightShifts(nums), 0);
}

TEST_P(MinimumRightShiftsToSortTheArrayTest, Example3) {
  std::vector<int> nums{2, 1, 4};
  EXPECT_EQ(solution_.minimumRightShifts(nums), -1);
}

TEST_P(MinimumRightShiftsToSortTheArrayTest, SelfAuthoredSingleElement) {
  std::vector<int> nums{7};
  EXPECT_EQ(solution_.minimumRightShifts(nums), 0);
}

TEST_P(MinimumRightShiftsToSortTheArrayTest, SelfAuthoredRotatedAtFront) {
  std::vector<int> nums{5, 1, 2, 3, 4};
  EXPECT_EQ(solution_.minimumRightShifts(nums), 4);
}

INSTANTIATE_TEST_SUITE_P(
    MinimumRightShiftsToSortTheArrayTestSuite,
    MinimumRightShiftsToSortTheArrayTest,
    ::testing::ValuesIn(
        MinimumRightShiftsToSortTheArraySolution().getStrategyNames()));
