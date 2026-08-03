#include <gtest/gtest.h>

#include "leetcode/problems/reach-a-number.h"

using namespace leetcode::problem_754;

class ReachANumberTest : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }
  ReachANumberSolution solution;
};

TEST_P(ReachANumberTest, OfficialExamples) {
  EXPECT_EQ(solution.reachNumber(2), 3);
  EXPECT_EQ(solution.reachNumber(3), 2);
}

TEST_P(ReachANumberTest, SelfAuthored) {
  // target = 1: 1 step, 0→1
  EXPECT_EQ(solution.reachNumber(1), 1);
  // target = -2: same as 2 → 3
  EXPECT_EQ(solution.reachNumber(-2), 3);
  // target = 4: 1+2+3=6, diff=2 even → 3 steps
  EXPECT_EQ(solution.reachNumber(4), 3);
  // target = 5: n=3 sum=6 diff=1 odd, n odd → n+2=5
  EXPECT_EQ(solution.reachNumber(5), 5);
  // target = 6: n=3 sum=6 diff=0 → 3
  EXPECT_EQ(solution.reachNumber(6), 3);
}

INSTANTIATE_TEST_SUITE_P(,
                         ReachANumberTest,
                         testing::ValuesIn(ReachANumberSolution().getStrategyNames()));
