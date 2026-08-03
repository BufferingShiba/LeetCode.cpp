#include "leetcode/problems/additive-number.h"

#include "gtest/gtest.h"

namespace leetcode {
namespace problem_306 {

class AdditiveNumberTest : public ::testing::TestWithParam<string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  AdditiveNumberSolution solution;
};

TEST_P(AdditiveNumberTest, Example1) {
  EXPECT_TRUE(solution.isAdditiveNumber("112358"));
}

TEST_P(AdditiveNumberTest, Example2) {
  EXPECT_TRUE(solution.isAdditiveNumber("199100199"));
}

TEST_P(AdditiveNumberTest, LeadingZeroInvalid) {
  EXPECT_FALSE(solution.isAdditiveNumber("1023"));
}

TEST_P(AdditiveNumberTest, TooShort) {
  EXPECT_FALSE(solution.isAdditiveNumber("12"));
}

TEST_P(AdditiveNumberTest, ZeroStartValid) {
  EXPECT_TRUE(solution.isAdditiveNumber("011235"));
}

INSTANTIATE_TEST_SUITE_P(
    LeetCode, AdditiveNumberTest,
    ::testing::ValuesIn(AdditiveNumberSolution().getStrategyNames()));

}  // namespace problem_306
}  // namespace leetcode
