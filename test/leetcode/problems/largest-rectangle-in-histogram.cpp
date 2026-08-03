#include "leetcode/problems/largest-rectangle-in-histogram.h"

#include <gtest/gtest.h>

#include <string>
#include <vector>

namespace leetcode {
namespace problem_84 {
namespace {

class LargestRectangleInHistogramTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  LargestRectangleInHistogramSolution solution;
};

TEST_P(LargestRectangleInHistogramTest, Example1) {
  std::vector<int> heights = {2, 1, 5, 6, 2, 3};
  EXPECT_EQ(solution.largestRectangleArea(heights), 10);
}

TEST_P(LargestRectangleInHistogramTest, Example2) {
  std::vector<int> heights = {2, 4};
  EXPECT_EQ(solution.largestRectangleArea(heights), 4);
}

TEST_P(LargestRectangleInHistogramTest, SelfAuthoredSingleBar) {
  std::vector<int> heights = {1};
  EXPECT_EQ(solution.largestRectangleArea(heights), 1);
}

TEST_P(LargestRectangleInHistogramTest, SelfAuthoredZeroElement) {
  std::vector<int> heights = {0};
  EXPECT_EQ(solution.largestRectangleArea(heights), 0);
}

TEST_P(LargestRectangleInHistogramTest, SelfAuthoredDecreasing) {
  std::vector<int> heights = {6, 5, 4, 3, 2, 1};
  EXPECT_EQ(solution.largestRectangleArea(heights), 12);
}

TEST_P(LargestRectangleInHistogramTest, SelfAuthoredAllEqual) {
  std::vector<int> heights = {2, 2, 2, 2};
  EXPECT_EQ(solution.largestRectangleArea(heights), 8);
}

INSTANTIATE_TEST_SUITE_P(
    LargestRectangleInHistogramTestSuite,
    LargestRectangleInHistogramTest,
    ::testing::ValuesIn(LargestRectangleInHistogramSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_84
}  // namespace leetcode
