#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/apply-operations-to-make-sum-of-array-greater-than-or-equal-to-k.h"

namespace leetcode::problem_3091 {
namespace {

class ApplyOperationsToMakeSumOfArrayGreaterThanOrEqualToKTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  ApplyOperationsToMakeSumOfArrayGreaterThanOrEqualToKSolution solution;
};

TEST_P(ApplyOperationsToMakeSumOfArrayGreaterThanOrEqualToKTest, Example1) {
  EXPECT_EQ(solution.minOperations(11), 5);
}

TEST_P(ApplyOperationsToMakeSumOfArrayGreaterThanOrEqualToKTest, Example2) {
  EXPECT_EQ(solution.minOperations(1), 0);
}

TEST_P(ApplyOperationsToMakeSumOfArrayGreaterThanOrEqualToKTest, SelfAuthoredEdgeCaseTwo) {
  EXPECT_EQ(solution.minOperations(2), 1);
}

TEST_P(ApplyOperationsToMakeSumOfArrayGreaterThanOrEqualToKTest, SelfAuthoredEdgeCaseSmallK) {
  EXPECT_EQ(solution.minOperations(3), 2);
}

TEST_P(ApplyOperationsToMakeSumOfArrayGreaterThanOrEqualToKTest, SelfAuthoredEdgeCaseSquare) {
  // k = 4 -> v=2, copies=1 -> ops=2
  EXPECT_EQ(solution.minOperations(4), 2);
}

INSTANTIATE_TEST_SUITE_P(
    ApplyOperationsToMakeSumOfArrayGreaterThanOrEqualToKTest,
    ApplyOperationsToMakeSumOfArrayGreaterThanOrEqualToKTest,
    ::testing::ValuesIn(
        ApplyOperationsToMakeSumOfArrayGreaterThanOrEqualToKSolution()
            .getStrategyNames()));

}  // namespace
}  // namespace leetcode::problem_3091
