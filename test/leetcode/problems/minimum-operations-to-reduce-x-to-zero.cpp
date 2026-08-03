#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/minimum-operations-to-reduce-x-to-zero.h"

namespace leetcode::problem_1658 {

class MinimumOperationsToReduceXToZeroTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override {
    solution_.setStrategy(GetParam());
  }

  void RunTest(const std::vector<int>& nums, int x, int expected) {
    std::vector<int> input = nums;
    EXPECT_EQ(solution_.minOperations(input, x), expected);
  }

  MinimumOperationsToReduceXToZeroSolution solution_;
};

TEST_P(MinimumOperationsToReduceXToZeroTest, Example1) {
  RunTest({1, 1, 4, 2, 3}, 5, 2);
}

TEST_P(MinimumOperationsToReduceXToZeroTest, Example2) {
  RunTest({5, 6, 7, 8, 9}, 4, -1);
}

TEST_P(MinimumOperationsToReduceXToZeroTest, Example3) {
  RunTest({3, 2, 20, 1, 1, 3}, 10, 5);
}

TEST_P(MinimumOperationsToReduceXToZeroTest, SelfAuthoredXCountsAll) {
  RunTest({3, 2, 20, 1, 1, 3}, 30, 6);
}

TEST_P(MinimumOperationsToReduceXToZeroTest, SelfAuthoredSingleElementExact) {
  RunTest({5}, 5, 1);
}

TEST_P(MinimumOperationsToReduceXToZeroTest, SelfAuthoredSingleElementImpossible) {
  RunTest({5}, 7, -1);
}

INSTANTIATE_TEST_SUITE_P(
    MinimumOperationsToReduceXToZeroTestSuite,
    MinimumOperationsToReduceXToZeroTest,
    ::testing::ValuesIn(
        MinimumOperationsToReduceXToZeroSolution().getStrategyNames()));

}  // namespace leetcode::problem_1658
