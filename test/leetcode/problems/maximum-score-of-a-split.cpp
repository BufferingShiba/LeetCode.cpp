#include "leetcode/problems/maximum-score-of-a-split.h"

#include <gtest/gtest.h>

#include <string>
#include <vector>

namespace leetcode {
namespace problem_3788 {

class MaximumScoreOfASplitTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  MaximumScoreOfASplitSolution solution_;
};

TEST_P(MaximumScoreOfASplitTest, Example1) {
  std::vector<int> nums = {10, -1, 3, -4, -5};
  EXPECT_EQ(17, solution_.maximumScore(nums));
}

TEST_P(MaximumScoreOfASplitTest, Example2) {
  std::vector<int> nums = {-7, -5, 3};
  EXPECT_EQ(-2, solution_.maximumScore(nums));
}

TEST_P(MaximumScoreOfASplitTest, Example3) {
  std::vector<int> nums = {1, 1};
  EXPECT_EQ(0, solution_.maximumScore(nums));
}

TEST_P(MaximumScoreOfASplitTest, SelfAuthoredTwoElementsNegative) {
  std::vector<int> nums = {-5, -10};
  // score(0) = (-5) - (-10) = 5
  EXPECT_EQ(5, solution_.maximumScore(nums));
}

INSTANTIATE_TEST_SUITE_P(
    MaximumScoreOfASplitTests, MaximumScoreOfASplitTest,
    ::testing::ValuesIn(MaximumScoreOfASplitSolution().getStrategyNames()));

}  // namespace problem_3788
}  // namespace leetcode
