#include <gtest/gtest.h>

#include "leetcode/problems/power-of-three.h"

namespace leetcode {
namespace problem_326 {

class PowerOfThreeTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  PowerOfThreeSolution solution;
};

TEST_P(PowerOfThreeTest, Example1) {
  EXPECT_TRUE(solution.isPowerOfThree(27));
}

TEST_P(PowerOfThreeTest, Example2) {
  EXPECT_FALSE(solution.isPowerOfThree(0));
}

TEST_P(PowerOfThreeTest, Example3) {
  EXPECT_FALSE(solution.isPowerOfThree(-1));
}

TEST_P(PowerOfThreeTest, SelfAuthoredSmallPowers) {
  EXPECT_TRUE(solution.isPowerOfThree(1));
  EXPECT_TRUE(solution.isPowerOfThree(3));
  EXPECT_TRUE(solution.isPowerOfThree(81));
}

TEST_P(PowerOfThreeTest, SelfAuthoredNonPowers) {
  EXPECT_FALSE(solution.isPowerOfThree(2));
  EXPECT_FALSE(solution.isPowerOfThree(45));
  EXPECT_FALSE(solution.isPowerOfThree(-27));
}

INSTANTIATE_TEST_SUITE_P(
    PowerOfThreeTestCases, PowerOfThreeTest,
    ::testing::ValuesIn(PowerOfThreeSolution().getStrategyNames()));

}  // namespace problem_326
}  // namespace leetcode
