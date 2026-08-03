#include "leetcode/problems/power-of-four.h"

#include <gtest/gtest.h>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_342 {
namespace {

class PowerOfFourTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  PowerOfFourSolution solution;
};

TEST_P(PowerOfFourTest, Example1) {
  EXPECT_TRUE(solution.isPowerOfFour(16));
}

TEST_P(PowerOfFourTest, Example2) {
  EXPECT_FALSE(solution.isPowerOfFour(5));
}

TEST_P(PowerOfFourTest, Example3) {
  EXPECT_TRUE(solution.isPowerOfFour(1));
}

TEST_P(PowerOfFourTest, SelfAuthored) {
  // 4^3 = 64
  EXPECT_TRUE(solution.isPowerOfFour(64));
  // 4^4 = 256
  EXPECT_TRUE(solution.isPowerOfFour(256));
  // 8 is a power of two but not a power of four
  EXPECT_FALSE(solution.isPowerOfFour(8));
  // negative / zero
  EXPECT_FALSE(solution.isPowerOfFour(0));
  EXPECT_FALSE(solution.isPowerOfFour(-4));
  // 2 is not a power of four
  EXPECT_FALSE(solution.isPowerOfFour(2));
}

INSTANTIATE_TEST_SUITE_P(
    PowerOfFourTestSuite, PowerOfFourTest,
    ::testing::ValuesIn(PowerOfFourSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_342
}  // namespace leetcode
