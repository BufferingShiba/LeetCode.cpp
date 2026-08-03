#include <gtest/gtest.h>

#include "leetcode/problems/check-if-point-is-reachable.h"

namespace leetcode {
namespace problem_2543 {

class CheckIfPointIsReachableTest
    : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  CheckIfPointIsReachableSolution solution_;
};

TEST_P(CheckIfPointIsReachableTest, Example1) {
  EXPECT_FALSE(solution_.isReachable(6, 9));
}

TEST_P(CheckIfPointIsReachableTest, Example2) {
  EXPECT_TRUE(solution_.isReachable(4, 7));
}

TEST_P(CheckIfPointIsReachableTest, SelfAuthoredBothOne) {
  EXPECT_TRUE(solution_.isReachable(1, 1));
}

TEST_P(CheckIfPointIsReachableTest, SelfAuthoredPowerOfTwo) {
  EXPECT_TRUE(solution_.isReachable(8, 1));
  EXPECT_TRUE(solution_.isReachable(1, 16));
  EXPECT_TRUE(solution_.isReachable(2, 4));
}

TEST_P(CheckIfPointIsReachableTest, SelfAuthoredGcdNotPowerOfTwo) {
  EXPECT_FALSE(solution_.isReachable(3, 3));
  EXPECT_FALSE(solution_.isReachable(10, 15));
  EXPECT_FALSE(solution_.isReachable(9, 12));
}

TEST_P(CheckIfPointIsReachableTest, SelfAuthoredLargeCoprime) {
  // gcd = 1 => power of 2, should be reachable
  EXPECT_TRUE(solution_.isReachable(1000000000, 999999999));
}

INSTANTIATE_TEST_SUITE_P(
    Strategies, CheckIfPointIsReachableTest,
    testing::ValuesIn(
        CheckIfPointIsReachableSolution().getStrategyNames()));

}  // namespace problem_2543
}  // namespace leetcode
