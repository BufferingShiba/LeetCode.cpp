#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/number-of-different-integers-in-a-string.h"

namespace leetcode {
namespace problem_1805 {

class NumberOfDifferentIntegersInAStringTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  NumberOfDifferentIntegersInAStringSolution solution;
};

TEST_P(NumberOfDifferentIntegersInAStringTest, Example1) {
  EXPECT_EQ(solution.numDifferentIntegers("a123bc34d8ef34"), 3);
}

TEST_P(NumberOfDifferentIntegersInAStringTest, Example2) {
  EXPECT_EQ(solution.numDifferentIntegers("leet1234code234"), 2);
}

TEST_P(NumberOfDifferentIntegersInAStringTest, Example3) {
  EXPECT_EQ(solution.numDifferentIntegers("a1b01c001"), 1);
}

TEST_P(NumberOfDifferentIntegersInAStringTest, SelfAuthoredAllZeroDigits) {
  EXPECT_EQ(solution.numDifferentIntegers("000"), 1);
}

TEST_P(NumberOfDifferentIntegersInAStringTest, SelfAuthoredMixedLeadingZeros) {
  EXPECT_EQ(solution.numDifferentIntegers("0a00b000c1"), 2);
}

INSTANTIATE_TEST_SUITE_P(
    NumberOfDifferentIntegersInAStringTestSuite,
    NumberOfDifferentIntegersInAStringTest,
    ::testing::ValuesIn(
        NumberOfDifferentIntegersInAStringSolution().getStrategyNames()));

}  // namespace problem_1805
}  // namespace leetcode
