#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/distribute-money-to-maximum-children.h"

namespace leetcode {
namespace problem_2591 {

class DistributeMoneyToMaximumChildrenTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  DistributeMoneyToMaximumChildrenSolution solution;

  void SetUp() override { solution.setStrategy(GetParam()); }
};

TEST_P(DistributeMoneyToMaximumChildrenTest, Example1) {
  EXPECT_EQ(solution.distMoney(20, 3), 1);
}

TEST_P(DistributeMoneyToMaximumChildrenTest, Example2) {
  EXPECT_EQ(solution.distMoney(16, 2), 2);
}

TEST_P(DistributeMoneyToMaximumChildrenTest, NotEnoughMoney) {
  EXPECT_EQ(solution.distMoney(1, 2), -1);
}

TEST_P(DistributeMoneyToMaximumChildrenTest, SingleChildRemaining) {
  EXPECT_EQ(solution.distMoney(8, 2), 0);
}

TEST_P(DistributeMoneyToMaximumChildrenTest, AvoidFour) {
  EXPECT_EQ(solution.distMoney(12, 2), 0);
}

namespace {
DistributeMoneyToMaximumChildrenSolution g_testSolution;
}  // namespace


// LeetCode 失败用例: WrongAnswerCase1
TEST_P(DistributeMoneyToMaximumChildrenTest, WrongAnswerCase1) {
  // money = 17, children = 2
    // 期望: 1 (只有 1 个孩子正好拿到 8，另一个拿到 9)
    EXPECT_EQ(solution.distMoney(17, 2), 1);
}
INSTANTIATE_TEST_SUITE_P(
    DistributeMoneyToMaximumChildrenTestSuite,
    DistributeMoneyToMaximumChildrenTest,
    ::testing::ValuesIn(g_testSolution.getStrategyNames()));

}  // namespace problem_2591
}  // namespace leetcode
