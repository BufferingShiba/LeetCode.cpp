#include <gtest/gtest.h>

#include "leetcode/problems/maximum-points-inside-the-square.h"

#include <string>
#include <vector>

using leetcode::problem_3143::MaximumPointsInsideTheSquareSolution;

namespace leetcode {
namespace problem_3143 {

testing::AssertionResult runAndCheck(
    std::vector<std::vector<int>> points, const std::string& s,
    int expected, const std::string& strategy) {
  MaximumPointsInsideTheSquareSolution solution;
  solution.setStrategy(strategy);
  std::string tag = s;
  int actual = solution.maxPointsInsideSquare(points, tag);
  if (actual == expected) {
    return testing::AssertionSuccess();
  }
  return testing::AssertionFailure()
         << "actual=" << actual << " expected=" << expected;
}

class MaximumPointsInsideTheSquareTest
    : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override {}
};

TEST_P(MaximumPointsInsideTheSquareTest, Example1) {
  auto strategy = GetParam();
  EXPECT_TRUE(runAndCheck(
      {{2, 2}, {-1, -2}, {-4, 4}, {-3, 1}, {3, -3}}, "abdca", 2, strategy));
}

TEST_P(MaximumPointsInsideTheSquareTest, Example2) {
  auto strategy = GetParam();
  EXPECT_TRUE(runAndCheck(
      {{1, 1}, {-2, -2}, {-2, 2}}, "abb", 1, strategy));
}

TEST_P(MaximumPointsInsideTheSquareTest, Example3) {
  auto strategy = GetParam();
  EXPECT_TRUE(runAndCheck(
      {{1, 1}, {-1, -1}, {2, -2}}, "ccd", 0, strategy));
}

TEST_P(MaximumPointsInsideTheSquareTest, SelfAuthored) {
  auto strategy = GetParam();

  // Single point always counts (side length can be 0).
  EXPECT_TRUE(runAndCheck({{0, 0}}, "a", 1, strategy));

  // Two same-tag points with different distances: the farther one must be excluded.
  EXPECT_TRUE(runAndCheck({{5, 5}, {1, 1}}, "aa", 1, strategy));
}

INSTANTIATE_TEST_SUITE_P(
    MaximumPointsInsideTheSquareTests, MaximumPointsInsideTheSquareTest,
    testing::ValuesIn(MaximumPointsInsideTheSquareSolution().getStrategyNames()));

}  // namespace problem_3143
}  // namespace leetcode
