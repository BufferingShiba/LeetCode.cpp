#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/maximum-number-of-operations-to-move-ones-to-the-end.h"

namespace leetcode::problem_3228 {

class MaximumNumberOfOperationsToMoveOnesToTheEndTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  MaximumNumberOfOperationsToMoveOnesToTheEndSolution solution;

  void SetUp() override { solution.setStrategy(GetParam()); }
};

TEST_P(MaximumNumberOfOperationsToMoveOnesToTheEndTest, Example1) {
  EXPECT_EQ(solution.maxOperations("1001101"), 4);
}

TEST_P(MaximumNumberOfOperationsToMoveOnesToTheEndTest, Example2) {
  EXPECT_EQ(solution.maxOperations("00111"), 0);
}

TEST_P(MaximumNumberOfOperationsToMoveOnesToTheEndTest, SelfAuthoredSingleZeroBlockSuffix) {
  EXPECT_EQ(solution.maxOperations("111000"), 0);
}

TEST_P(MaximumNumberOfOperationsToMoveOnesToTheEndTest, SelfAuthoredAlternating) {
  EXPECT_EQ(solution.maxOperations("101"), 1);
}

INSTANTIATE_TEST_SUITE_P(
    MaximumNumberOfOperationsToMoveOnesToTheEndTests,
    MaximumNumberOfOperationsToMoveOnesToTheEndTest,
    ::testing::ValuesIn(
        MaximumNumberOfOperationsToMoveOnesToTheEndSolution()
            .getStrategyNames()));

}  // namespace leetcode::problem_3228
