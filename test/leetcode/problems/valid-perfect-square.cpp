#include <gtest/gtest.h>

#include "leetcode/problems/valid-perfect-square.h"

namespace leetcode {
namespace problem_367 {
namespace {

class ValidPerfectSquareTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  ValidPerfectSquareSolution solution;
};

TEST_P(ValidPerfectSquareTest, Example1) {
  EXPECT_TRUE(solution.isPerfectSquare(16));
}

TEST_P(ValidPerfectSquareTest, Example2) {
  EXPECT_FALSE(solution.isPerfectSquare(14));
}

TEST_P(ValidPerfectSquareTest, SelfAuthoredEdgeCaseOne) {
  EXPECT_TRUE(solution.isPerfectSquare(1));
}

TEST_P(ValidPerfectSquareTest, SelfAuthoredEdgeCaseMax) {
  EXPECT_TRUE(solution.isPerfectSquare(2147395600));
}

TEST_P(ValidPerfectSquareTest, SelfAuthoredNonSquareLarge) {
  EXPECT_FALSE(solution.isPerfectSquare(2147483647));
}

INSTANTIATE_TEST_SUITE_P(
    ValidPerfectSquareTestSuite, ValidPerfectSquareTest,
    ::testing::ValuesIn(ValidPerfectSquareSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_367
}  // namespace leetcode
