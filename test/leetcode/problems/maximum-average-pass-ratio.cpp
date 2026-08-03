#include <gtest/gtest.h>

#include "leetcode/problems/maximum-average-pass-ratio.h"

namespace leetcode::problem_1792 {

class MaximumAveragePassRatioTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }
  MaximumAveragePassRatioSolution solution_;
};

TEST_P(MaximumAveragePassRatioTest, Example1) {
  std::vector<std::vector<int>> classes = {{1, 2}, {3, 5}, {2, 2}};
  int extraStudents = 2;
  double expected = 0.78333;
  double result = solution_.maxAverageRatio(classes, extraStudents);
  EXPECT_NEAR(result, expected, 1e-5);
}

TEST_P(MaximumAveragePassRatioTest, Example2) {
  std::vector<std::vector<int>> classes = {{2, 4}, {3, 9}, {4, 5}, {2, 10}};
  int extraStudents = 4;
  double expected = 0.53485;
  double result = solution_.maxAverageRatio(classes, extraStudents);
  EXPECT_NEAR(result, expected, 1e-5);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies, MaximumAveragePassRatioTest,
    ::testing::ValuesIn(MaximumAveragePassRatioSolution().getStrategyNames()));

}  // namespace leetcode::problem_1792
