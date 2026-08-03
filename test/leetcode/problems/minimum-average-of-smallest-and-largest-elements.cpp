#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/minimum-average-of-smallest-and-largest-elements.h"

namespace leetcode::problem_3194 {

class MinimumAverageOfSmallestAndLargestElementsTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  MinimumAverageOfSmallestAndLargestElementsSolution solution_;
};

TEST_P(MinimumAverageOfSmallestAndLargestElementsTest, Example1) {
  std::vector<int> nums = {7, 8, 3, 4, 15, 13, 4, 1};
  EXPECT_DOUBLE_EQ(5.5, solution_.minimumAverage(nums));
}

TEST_P(MinimumAverageOfSmallestAndLargestElementsTest, Example2) {
  std::vector<int> nums = {1, 9, 8, 3, 10, 5};
  EXPECT_DOUBLE_EQ(5.5, solution_.minimumAverage(nums));
}

TEST_P(MinimumAverageOfSmallestAndLargestElementsTest, Example3) {
  std::vector<int> nums = {1, 2, 3, 7, 8, 9};
  EXPECT_DOUBLE_EQ(5.0, solution_.minimumAverage(nums));
}

TEST_P(MinimumAverageOfSmallestAndLargestElementsTest, SelfAuthoredAllEqual) {
  std::vector<int> nums = {5, 5, 5, 5};
  EXPECT_DOUBLE_EQ(5.0, solution_.minimumAverage(nums));
}

TEST_P(MinimumAverageOfSmallestAndLargestElementsTest, SelfAuthoredTwoElements) {
  std::vector<int> nums = {2, 4};
  EXPECT_DOUBLE_EQ(3.0, solution_.minimumAverage(nums));
}

INSTANTIATE_TEST_SUITE_P(
    MinimumAverageOfSmallestAndLargestElementsTests,
    MinimumAverageOfSmallestAndLargestElementsTest,
    ::testing::ValuesIn(
        MinimumAverageOfSmallestAndLargestElementsSolution().getStrategyNames()));

}  // namespace leetcode::problem_3194
