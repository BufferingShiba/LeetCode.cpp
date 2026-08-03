#include <string>
#include <vector>

#include "leetcode/problems/least-operators-to-express-number.h"

#include <gtest/gtest.h>

namespace leetcode {
namespace problem_964 {
namespace {

class LeastOperatorsToExpressNumberTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  LeastOperatorsToExpressNumberSolution solution;
};

TEST_P(LeastOperatorsToExpressNumberTest, Example1) {
  EXPECT_EQ(solution.leastOpsExpressTarget(3, 19), 5);
}

TEST_P(LeastOperatorsToExpressNumberTest, Example2) {
  EXPECT_EQ(solution.leastOpsExpressTarget(5, 501), 8);
}

TEST_P(LeastOperatorsToExpressNumberTest, Example3) {
  EXPECT_EQ(solution.leastOpsExpressTarget(100, 100000000), 3);
}

TEST_P(LeastOperatorsToExpressNumberTest, SelfAuthoredSmallOne) {
  EXPECT_EQ(solution.leastOpsExpressTarget(2, 1), 1);   // 2/2
  EXPECT_EQ(solution.leastOpsExpressTarget(3, 2), 2);   // 3 - 3/3
  EXPECT_EQ(solution.leastOpsExpressTarget(2, 3), 2);   // 2 + 2/2
}

TEST_P(LeastOperatorsToExpressNumberTest, SelfAuthoredPowerTerm) {
  EXPECT_EQ(solution.leastOpsExpressTarget(3, 27), 2);  // 3*3*3
  EXPECT_EQ(solution.leastOpsExpressTarget(2, 8), 2);   // 2*2*2
}

TEST_P(LeastOperatorsToExpressNumberTest, SelfAuthoredBorrowCase) {
  // 5*5 - 1 = 24  (x=5) => ops: * - / = 3
  EXPECT_EQ(solution.leastOpsExpressTarget(5, 24), 3);
}


// LeetCode 失败用例: WrongAnswerCase1
TEST_P(LeastOperatorsToExpressNumberTest, WrongAnswerCase1) {
  // 输入: x = 97, target = 178890910
    // 期望: 76
    EXPECT_EQ(solution.leastOpsExpressTarget(97, 178890910), 76);
}
INSTANTIATE_TEST_SUITE_P(
    LeastOperatorsToExpressNumberTestSuite,
    LeastOperatorsToExpressNumberTest,
    ::testing::ValuesIn(LeastOperatorsToExpressNumberSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_964
}  // namespace leetcode
