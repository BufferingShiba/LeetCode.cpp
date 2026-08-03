#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/subtract-the-product-and-sum-of-digits-of-an-integer.h"

namespace leetcode {
namespace problem_1281 {
namespace {

using SubtractiveTest = testing::TestWithParam<std::string>;

}  // namespace

class SubtractTheProductAndSumOfDigitsOfAnIntegerTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  SubtractTheProductAndSumOfDigitsOfAnIntegerSolution solution;
};

TEST_P(SubtractTheProductAndSumOfDigitsOfAnIntegerTest, Example1) {
  EXPECT_EQ(solution.subtractProductAndSum(234), 15);
}

TEST_P(SubtractTheProductAndSumOfDigitsOfAnIntegerTest, Example2) {
  EXPECT_EQ(solution.subtractProductAndSum(4421), 21);
}

TEST_P(SubtractTheProductAndSumOfDigitsOfAnIntegerTest, SelfAuthoredSingleDigit) {
  EXPECT_EQ(solution.subtractProductAndSum(7), 0);
}

TEST_P(SubtractTheProductAndSumOfDigitsOfAnIntegerTest, SelfAuthoredContainsZero) {
  EXPECT_EQ(solution.subtractProductAndSum(120), -3);
}

INSTANTIATE_TEST_SUITE_P(
    SubtractTheProductAndSumOfDigitsOfAnIntegerTest,
    SubtractTheProductAndSumOfDigitsOfAnIntegerTest,
    testing::ValuesIn(
        SubtractTheProductAndSumOfDigitsOfAnIntegerSolution()
            .getStrategyNames()));

}  // namespace problem_1281
}  // namespace leetcode
