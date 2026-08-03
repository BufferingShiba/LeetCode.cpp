#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/largest-triangle-area.h"

namespace leetcode {
namespace problem_812 {
namespace {

class LargestTriangleAreaTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  LargestTriangleAreaSolution solution_;
};

TEST_P(LargestTriangleAreaTest, Example1) {
  std::vector<std::vector<int>> points = {{0, 0}, {0, 1}, {1, 0}, {0, 2}, {2, 0}};
  EXPECT_NEAR(solution_.largestTriangleArea(points), 2.0, 1e-5);
}

TEST_P(LargestTriangleAreaTest, Example2) {
  std::vector<std::vector<int>> points = {{1, 0}, {0, 0}, {0, 1}};
  EXPECT_NEAR(solution_.largestTriangleArea(points), 0.5, 1e-5);
}

TEST_P(LargestTriangleAreaTest, SelfAuthoredCollinearPoints) {
  std::vector<std::vector<int>> points = {{-1, 0}, {0, 0}, {1, 0}};
  EXPECT_NEAR(solution_.largestTriangleArea(points), 0.0, 1e-5);
}

INSTANTIATE_TEST_SUITE_P(
    LargestTriangleAreaTestSuite, LargestTriangleAreaTest,
    ::testing::ValuesIn(LargestTriangleAreaSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_812
}  // namespace leetcode
