#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/minimum-operations-to-reduce-an-integer-to-0.h"

namespace leetcode {
namespace problem_2571 {

class MinimumOperationsToReduceAnIntegerTo0Test
    : public ::testing::TestWithParam<std::string> {
 protected:
  MinimumOperationsToReduceAnIntegerTo0Solution solution;

  void SetUp() override { solution.setStrategy(GetParam()); }
};

TEST_P(MinimumOperationsToReduceAnIntegerTo0Test, Example1) {
  EXPECT_EQ(3, solution.minOperations(39));
}

TEST_P(MinimumOperationsToReduceAnIntegerTo0Test, Example2) {
  EXPECT_EQ(3, solution.minOperations(54));
}

TEST_P(MinimumOperationsToReduceAnIntegerTo0Test, SelfAuthoredSingleBit) {
  // n is already a power of 2.
  EXPECT_EQ(1, solution.minOperations(1));
  EXPECT_EQ(1, solution.minOperations(8));
  EXPECT_EQ(1, solution.minOperations(65536));
}

TEST_P(MinimumOperationsToReduceAnIntegerTo0Test, SelfAuthoredSmallValues) {
  // n=2 is 2^1 -> one operation.
  EXPECT_EQ(1, solution.minOperations(2));
  // n=3 = 11 -> add 1 -> 4 -> subtract 4: two operations.
  EXPECT_EQ(2, solution.minOperations(3));
  // n=7 = 111 -> add 1 -> 8 -> subtract 8: two operations.
  EXPECT_EQ(2, solution.minOperations(7));
  // n=6 = 110 -> subtract 2 -> 4 -> subtract 4: two operations.
  EXPECT_EQ(2, solution.minOperations(6));
}

INSTANTIATE_TEST_SUITE_P(
    MinimumOperationsToReduceAnIntegerTo0Strategies,
    MinimumOperationsToReduceAnIntegerTo0Test,
    ::testing::ValuesIn(
        MinimumOperationsToReduceAnIntegerTo0Solution().getStrategyNames()));

}  // namespace problem_2571
}  // namespace leetcode
