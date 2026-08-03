#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/find-the-pivot-integer.h"

namespace leetcode {
namespace problem_2485 {

class FindThePivotIntegerTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }
  FindThePivotIntegerSolution solution;
};

TEST_P(FindThePivotIntegerTest, Example1) {
  EXPECT_EQ(solution.pivotInteger(8), 6);
}

TEST_P(FindThePivotIntegerTest, Example2) {
  EXPECT_EQ(solution.pivotInteger(1), 1);
}

TEST_P(FindThePivotIntegerTest, Example3) {
  EXPECT_EQ(solution.pivotInteger(4), -1);
}

TEST_P(FindThePivotIntegerTest, SelfAuthoredNoPivot) {
  EXPECT_EQ(solution.pivotInteger(2), -1);
}

TEST_P(FindThePivotIntegerTest, SelfAuthoredPivot) {
  // n = 49, total = 49*50/2 = 1225 = 35^2
  EXPECT_EQ(solution.pivotInteger(49), 35);
}

INSTANTIATE_TEST_SUITE_P(
    FindThePivotIntegerTestSuite, FindThePivotIntegerTest,
    ::testing::ValuesIn(FindThePivotIntegerSolution().getStrategyNames()));

}  // namespace problem_2485
}  // namespace leetcode
