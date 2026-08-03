#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/k-items-with-the-maximum-sum.h"

namespace leetcode {
namespace problem_2600 {
namespace {

class KItemsWithTheMaximumSumTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  KItemsWithTheMaximumSumSolution solution;
};

TEST_P(KItemsWithTheMaximumSumTest, Example1) {
  EXPECT_EQ(solution.kItemsWithMaximumSum(3, 2, 0, 2), 2);
}

TEST_P(KItemsWithTheMaximumSumTest, Example2) {
  EXPECT_EQ(solution.kItemsWithMaximumSum(3, 2, 0, 4), 3);
}

TEST_P(KItemsWithTheMaximumSumTest, NeedNegativeOnes) {
  EXPECT_EQ(solution.kItemsWithMaximumSum(2, 1, 3, 5), 0);  // 2*1 + 1*0 + 2*(-1)
}

TEST_P(KItemsWithTheMaximumSumTest, SingleNegative) {
  EXPECT_EQ(solution.kItemsWithMaximumSum(0, 0, 1, 1), -1);
}

TEST_P(KItemsWithTheMaximumSumTest, TakeZeroOnly) {
  EXPECT_EQ(solution.kItemsWithMaximumSum(0, 3, 0, 2), 0);
}

INSTANTIATE_TEST_SUITE_P(
    KItemsWithTheMaximumSumTestSuite, KItemsWithTheMaximumSumTest,
    ::testing::ValuesIn(KItemsWithTheMaximumSumSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_2600
}  // namespace leetcode
