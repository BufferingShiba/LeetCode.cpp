#include <gtest/gtest.h>

#include "leetcode/problems/sqrtx.h"

namespace leetcode::problem_69 {

class SqrtxTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  SqrtxSolution solution;
};

TEST_P(SqrtxTest, Example1) {
  EXPECT_EQ(solution.mySqrt(4), 2);
}

TEST_P(SqrtxTest, Example2) {
  EXPECT_EQ(solution.mySqrt(8), 2);
}

TEST_P(SqrtxTest, SelfAuthoredEdgeCases) {
  EXPECT_EQ(solution.mySqrt(0), 0);
  EXPECT_EQ(solution.mySqrt(1), 1);
  EXPECT_EQ(solution.mySqrt(2147395599), 46339);  // max floor sqrt within int range
}

INSTANTIATE_TEST_SUITE_P(Problem69Tests, SqrtxTest,
                         ::testing::ValuesIn(SqrtxSolution().getStrategyNames()));

}  // namespace leetcode::problem_69
