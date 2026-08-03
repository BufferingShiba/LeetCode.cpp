#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/number-of-bit-changes-to-make-two-integers-equal.h"

namespace leetcode {
namespace problem_3226 {

using leetcode::problem_3226::NumberOfBitChangesToMakeTwoIntegersEqualSolution;

class NumberOfBitChangesToMakeTwoIntegersEqualTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  NumberOfBitChangesToMakeTwoIntegersEqualSolution solution_;
};

TEST_P(NumberOfBitChangesToMakeTwoIntegersEqualTest, Example1) {
  EXPECT_EQ(solution_.minChanges(13, 4), 2);
}

TEST_P(NumberOfBitChangesToMakeTwoIntegersEqualTest, Example2) {
  EXPECT_EQ(solution_.minChanges(21, 21), 0);
}

TEST_P(NumberOfBitChangesToMakeTwoIntegersEqualTest, Example3) {
  EXPECT_EQ(solution_.minChanges(14, 13), -1);
}

TEST_P(NumberOfBitChangesToMakeTwoIntegersEqualTest, EdgeCaseZeroTarget) {
  EXPECT_EQ(solution_.minChanges(8, 0), 1);
}

TEST_P(NumberOfBitChangesToMakeTwoIntegersEqualTest, EdgeCaseImpossibleMax) {
  // n = 1 has only the lowest bit; k's higher bits cannot be created.
  EXPECT_EQ(solution_.minChanges(1, 1000000), -1);
}

INSTANTIATE_TEST_SUITE_P(
    NumberOfBitChangesToMakeTwoIntegersEqualTests,
    NumberOfBitChangesToMakeTwoIntegersEqualTest,
    ::testing::ValuesIn(
        NumberOfBitChangesToMakeTwoIntegersEqualSolution().getStrategyNames()));

}  // namespace problem_3226
}  // namespace leetcode
