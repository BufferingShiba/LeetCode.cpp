#include <gtest/gtest.h>

#include <string>

#include "leetcode/problems/a-number-after-a-double-reversal.h"

namespace leetcode {
namespace problem_2119 {

class ANumberAfterADoubleReversalTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  ANumberAfterADoubleReversalSolution solution;
};

TEST_P(ANumberAfterADoubleReversalTest, Example1) {
  EXPECT_TRUE(solution.isSameAfterReversals(526));
}

TEST_P(ANumberAfterADoubleReversalTest, Example2) {
  EXPECT_FALSE(solution.isSameAfterReversals(1800));
}

TEST_P(ANumberAfterADoubleReversalTest, Example3) {
  EXPECT_TRUE(solution.isSameAfterReversals(0));
}

TEST_P(ANumberAfterADoubleReversalTest, SelfAuthored) {
  EXPECT_FALSE(solution.isSameAfterReversals(10));
  EXPECT_FALSE(solution.isSameAfterReversals(100));
  EXPECT_TRUE(solution.isSameAfterReversals(1));
}

INSTANTIATE_TEST_SUITE_P(
    ANumberAfterADoubleReversalTestSuite, ANumberAfterADoubleReversalTest,
    ::testing::ValuesIn(ANumberAfterADoubleReversalSolution().getStrategyNames()));

}  // namespace problem_2119
}  // namespace leetcode
