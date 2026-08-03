#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/minimum-sum-of-four-digit-number-after-splitting-digits.h"

namespace leetcode {
namespace problem_2160 {

class MinimumSumOfFourDigitNumberAfterSplittingDigitsTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  MinimumSumOfFourDigitNumberAfterSplittingDigitsSolution solution;
};

TEST_P(MinimumSumOfFourDigitNumberAfterSplittingDigitsTest, Example1) {
  EXPECT_EQ(solution.minimumSum(2932), 52);
}

TEST_P(MinimumSumOfFourDigitNumberAfterSplittingDigitsTest, Example2) {
  EXPECT_EQ(solution.minimumSum(4009), 13);
}

TEST_P(MinimumSumOfFourDigitNumberAfterSplittingDigitsTest, SelfAuthoredSmallest) {
  EXPECT_EQ(solution.minimumSum(1000), 1);
}

TEST_P(MinimumSumOfFourDigitNumberAfterSplittingDigitsTest, SelfAuthoredAllSame) {
  EXPECT_EQ(solution.minimumSum(1111), 22);
}

INSTANTIATE_TEST_SUITE_P(
    MinimumSumOfFourDigitNumberAfterSplittingDigitsTestSuite,
    MinimumSumOfFourDigitNumberAfterSplittingDigitsTest,
    ::testing::ValuesIn(
        MinimumSumOfFourDigitNumberAfterSplittingDigitsSolution()
            .getStrategyNames()));

}  // namespace problem_2160
}  // namespace leetcode
