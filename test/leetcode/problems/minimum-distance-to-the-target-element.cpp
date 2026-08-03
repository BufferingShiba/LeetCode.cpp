#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/minimum-distance-to-the-target-element.h"

namespace leetcode::problem_1848 {

using MinimumDistanceToTheTargetElementSolutionT =
    MinimumDistanceToTheTargetElementSolution;

class MinimumDistanceToTheTargetElementTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  MinimumDistanceToTheTargetElementSolutionT solution_;
};

TEST_P(MinimumDistanceToTheTargetElementTest, Example1) {
  std::vector<int> nums{1, 2, 3, 4, 5};
  EXPECT_EQ(solution_.getMinDistance(nums, 5, 3), 1);
}

TEST_P(MinimumDistanceToTheTargetElementTest, Example2) {
  std::vector<int> nums{1};
  EXPECT_EQ(solution_.getMinDistance(nums, 1, 0), 0);
}

TEST_P(MinimumDistanceToTheTargetElementTest, Example3) {
  std::vector<int> nums{1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
  EXPECT_EQ(solution_.getMinDistance(nums, 1, 0), 0);
}

TEST_P(MinimumDistanceToTheTargetElementTest, SelfAuthoredTargetFarLeft) {
  std::vector<int> nums{1, 2, 3, 4, 5};
  EXPECT_EQ(solution_.getMinDistance(nums, 1, 4), 4);
}

TEST_P(MinimumDistanceToTheTargetElementTest, SelfAuthoredMultipleOccurrencesChooseNearest) {
  std::vector<int> nums{5, 2, 5, 2, 5};
  EXPECT_EQ(solution_.getMinDistance(nums, 5, 2), 0);
}

INSTANTIATE_TEST_SUITE_P(
    MinimumDistanceToTheTargetElementTest,
    MinimumDistanceToTheTargetElementTest,
    ::testing::ValuesIn(
        MinimumDistanceToTheTargetElementSolutionT().getStrategyNames()));

}  // namespace leetcode::problem_1848
