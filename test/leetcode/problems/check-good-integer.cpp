#include <gtest/gtest.h>

#include <string>

#include "leetcode/problems/check-good-integer.h"

using leetcode::problem_3959::CheckGoodIntegerSolution;

namespace {

const std::string kImpl = "digit-sum-simulation";

}  // namespace

class CheckGoodIntegerTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  CheckGoodIntegerSolution solution_;
};

TEST_P(CheckGoodIntegerTest, Example1) {
  EXPECT_FALSE(solution_.checkGoodInteger(1000));
}

TEST_P(CheckGoodIntegerTest, Example2) {
  EXPECT_TRUE(solution_.checkGoodInteger(19));
}

TEST_P(CheckGoodIntegerTest, SelfAuthoredLowerBoundNotEmpty) {
  // n = 1 -> digitSum = 1, squareSum = 1, diff = 0 < 50 => false.
  EXPECT_FALSE(solution_.checkGoodInteger(1));
}

TEST_P(CheckGoodIntegerTest, SelfAuthoredLargeGoodInteger) {
  // n = 999999999 -> digitSum = 81, squareSum = 9^2 * 9 = 729, diff = 648 >= 50.
  EXPECT_TRUE(solution_.checkGoodInteger(999999999));
}

INSTANTIATE_TEST_SUITE_P(
    CheckGoodIntegerTestSuite, CheckGoodIntegerTest,
    ::testing::ValuesIn(CheckGoodIntegerSolution().getStrategyNames()));
