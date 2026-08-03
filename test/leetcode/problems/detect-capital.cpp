#include <gtest/gtest.h>
#include "leetcode/problems/detect-capital.h"

using namespace leetcode::problem_520;

class DetectCapitalTest : public ::testing::TestWithParam<std::string> {
 protected:
  DetectCapitalSolution solution;
  void SetUp() override {
    solution.setStrategy(GetParam());
  }
};

TEST_P(DetectCapitalTest, OfficialCases) {
  EXPECT_TRUE(solution.detectCapitalUse("USA"));
  EXPECT_FALSE(solution.detectCapitalUse("FlaG"));
}

TEST_P(DetectCapitalTest, SelfAuthored) {
  EXPECT_TRUE(solution.detectCapitalUse("leetcode"));
  EXPECT_TRUE(solution.detectCapitalUse("Google"));
  EXPECT_TRUE(solution.detectCapitalUse("FLAG"));
  EXPECT_FALSE(solution.detectCapitalUse("FLag"));
  EXPECT_TRUE(solution.detectCapitalUse("a"));
  EXPECT_TRUE(solution.detectCapitalUse("A"));
  EXPECT_FALSE(solution.detectCapitalUse("uSA"));
  EXPECT_FALSE(solution.detectCapitalUse("aBc"));
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    DetectCapitalTest,
    ::testing::ValuesIn(DetectCapitalSolution().getStrategyNames()));
