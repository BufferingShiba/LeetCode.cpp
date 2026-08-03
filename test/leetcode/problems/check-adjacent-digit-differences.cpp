#include <gtest/gtest.h>

#include <string>

#include "leetcode/problems/check-adjacent-digit-differences.h"

namespace leetcode {
namespace problem_3931 {

class CheckAdjacentDigitDifferencesTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  CheckAdjacentDigitDifferencesSolution solution;
};

TEST_P(CheckAdjacentDigitDifferencesTest, Example1) {
  EXPECT_TRUE(solution.isAdjacentDiffAtMostTwo("132"));
}

TEST_P(CheckAdjacentDigitDifferencesTest, Example2) {
  EXPECT_FALSE(solution.isAdjacentDiffAtMostTwo("129"));
}

TEST_P(CheckAdjacentDigitDifferencesTest, SelfAuthoredAllSameDigits) {
  EXPECT_TRUE(solution.isAdjacentDiffAtMostTwo("555"));
}

TEST_P(CheckAdjacentDigitDifferencesTest, SelfAuthoredGapOfThree) {
  EXPECT_FALSE(solution.isAdjacentDiffAtMostTwo("147"));
}

INSTANTIATE_TEST_SUITE_P(
    CheckAdjacentDigitDifferencesTestSuite,
    CheckAdjacentDigitDifferencesTest,
    ::testing::ValuesIn(
        CheckAdjacentDigitDifferencesSolution().getStrategyNames()));

}  // namespace problem_3931
}  // namespace leetcode
