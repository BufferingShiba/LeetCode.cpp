#include <gtest/gtest.h>

#include "leetcode/problems/find-the-middle-index-in-array.h"

#include <vector>

namespace leetcode::problem_1991 {

class FindTheMiddleIndexInArrayTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  FindTheMiddleIndexInArraySolution solution_;
};

TEST_P(FindTheMiddleIndexInArrayTest, Example1) {
  std::vector<int> nums{2, 3, -1, 8, 4};
  EXPECT_EQ(3, solution_.findMiddleIndex(nums));
}

TEST_P(FindTheMiddleIndexInArrayTest, Example2) {
  std::vector<int> nums{1, -1, 4};
  EXPECT_EQ(2, solution_.findMiddleIndex(nums));
}

TEST_P(FindTheMiddleIndexInArrayTest, Example3) {
  std::vector<int> nums{2, 5};
  EXPECT_EQ(-1, solution_.findMiddleIndex(nums));
}

TEST_P(FindTheMiddleIndexInArrayTest, SelfAuthoredSingleElement) {
  std::vector<int> nums{7};
  EXPECT_EQ(0, solution_.findMiddleIndex(nums));
}

INSTANTIATE_TEST_SUITE_P(
    FindTheMiddleIndexInArrayTestSuite,
    FindTheMiddleIndexInArrayTest,
    ::testing::ValuesIn(FindTheMiddleIndexInArraySolution().getStrategyNames()));

}  // namespace leetcode::problem_1991
