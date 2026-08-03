#include <cmath>
#include <string>
#include <vector>

#include <gtest/gtest.h>

#include "leetcode/problems/powx-n.h"

namespace leetcode {
namespace problem_50 {

class PowxNTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  PowxNSolution solution;
};

TEST_P(PowxNTest, Example1) {
  EXPECT_NEAR(solution.myPow(2.0, 10), 1024.0, 1e-9);
}

TEST_P(PowxNTest, Example2) {
  EXPECT_NEAR(solution.myPow(2.1, 3), 9.261, 1e-9);
}

TEST_P(PowxNTest, Example3) {
  EXPECT_NEAR(solution.myPow(2.0, -2), 0.25, 1e-9);
}

TEST_P(PowxNTest, SelfAuthoredExponentZero) {
  EXPECT_NEAR(solution.myPow(3.0, 0), 1.0, 1e-9);
}

TEST_P(PowxNTest, SelfAuthoredNegativeBaseEvenExponent) {
  EXPECT_NEAR(solution.myPow(-2.0, 4), 16.0, 1e-9);
  EXPECT_NEAR(solution.myPow(-2.0, 3), -8.0, 1e-9);
}

TEST_P(PowxNTest, SelfAuthoredIntMinExponent) {
  // x = 1.0 with n = INT_MIN is safe (1^anything = 1).
  EXPECT_NEAR(solution.myPow(1.0, -2147483648), 1.0, 1e-9);
}

TEST_P(PowxNTest, SelfAuthoredBaseOne) {
  EXPECT_NEAR(solution.myPow(1.0, 1000000), 1.0, 1e-9);
}

INSTANTIATE_TEST_SUITE_P(PowxNTestSuite, PowxNTest,
                         ::testing::ValuesIn(PowxNSolution().getStrategyNames()));

}  // namespace problem_50
}  // namespace leetcode
