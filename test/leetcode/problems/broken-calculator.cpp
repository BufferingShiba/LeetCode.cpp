#include "leetcode/problems/broken-calculator.h"

#include "gtest/gtest.h"

namespace leetcode {
namespace problem_991 {

class BrokenCalculatorTest : public ::testing::TestWithParam<string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  BrokenCalculatorSolution solution;
};

TEST_P(BrokenCalculatorTest, Example1) {
  EXPECT_EQ(solution.brokenCalc(2, 3), 2);
}

TEST_P(BrokenCalculatorTest, Example2) {
  EXPECT_EQ(solution.brokenCalc(5, 8), 2);
}

TEST_P(BrokenCalculatorTest, Example3) {
  EXPECT_EQ(solution.brokenCalc(3, 10), 3);
}

INSTANTIATE_TEST_SUITE_P(
    LeetCode, BrokenCalculatorTest,
    ::testing::ValuesIn(BrokenCalculatorSolution().getStrategyNames()));

}  // namespace problem_991
}  // namespace leetcode
