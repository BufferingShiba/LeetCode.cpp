#include <gtest/gtest.h>
#include <string>

#include "leetcode/problems/ugly-number.h"

namespace leetcode::problem_263 {

class UglyNumberTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  UglyNumberSolution solution;
};

TEST_P(UglyNumberTest, Example1_n6) {
  EXPECT_TRUE(solution.isUgly(6));
}

TEST_P(UglyNumberTest, Example2_n1) {
  EXPECT_TRUE(solution.isUgly(1));
}

TEST_P(UglyNumberTest, Example3_n14) {
  EXPECT_FALSE(solution.isUgly(14));
}

TEST_P(UglyNumberTest, SelfAuthoredNonPositive) {
  EXPECT_FALSE(solution.isUgly(0));
  EXPECT_FALSE(solution.isUgly(-6));
  EXPECT_FALSE(solution.isUgly(-8));
}

TEST_P(UglyNumberTest, SelfAuthoredPurePowersOfUgly) {
  EXPECT_TRUE(solution.isUgly(8));
  EXPECT_TRUE(solution.isUgly(30));
  EXPECT_TRUE(solution.isUgly(100));
}

TEST_P(UglyNumberTest, SelfAuthoredHasOtherPrimeFactor) {
  EXPECT_FALSE(solution.isUgly(7));
  EXPECT_FALSE(solution.isUgly(49));
}

INSTANTIATE_TEST_SUITE_P(
    UglyNumberTestSuite, UglyNumberTest,
    ::testing::ValuesIn(UglyNumberSolution().getStrategyNames()));

}  // namespace leetcode::problem_263
