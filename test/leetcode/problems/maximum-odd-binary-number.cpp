#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/maximum-odd-binary-number.h"

namespace leetcode::problem_2864 {

class MaximumOddBinaryNumberTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  MaximumOddBinaryNumberSolution solution;

  void SetUp() override { solution.setStrategy(GetParam()); }
};

TEST_P(MaximumOddBinaryNumberTest, Example1) {
  EXPECT_EQ(solution.maximumOddBinaryNumber("010"), "001");
}

TEST_P(MaximumOddBinaryNumberTest, Example2) {
  EXPECT_EQ(solution.maximumOddBinaryNumber("0101"), "1001");
}

TEST_P(MaximumOddBinaryNumberTest, SelfAuthoredSingleOne) {
  EXPECT_EQ(solution.maximumOddBinaryNumber("100"), "001");
}

TEST_P(MaximumOddBinaryNumberTest, SelfAuthoredAllOnes) {
  EXPECT_EQ(solution.maximumOddBinaryNumber("1111"), "1111");
}

INSTANTIATE_TEST_SUITE_P(
    MaximumOddBinaryNumberTestSuite, MaximumOddBinaryNumberTest,
    ::testing::ValuesIn(MaximumOddBinaryNumberSolution().getStrategyNames()));

}  // namespace leetcode::problem_2864
