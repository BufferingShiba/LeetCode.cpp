#include <gtest/gtest.h>

#include <string>

#include "leetcode/problems/find-the-maximum-achievable-number.h"

namespace leetcode::problem_2769 {

class FindTheMaximumAchievableNumberTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  FindTheMaximumAchievableNumberSolution solution_;
};

TEST_P(FindTheMaximumAchievableNumberTest, Example1) {
  EXPECT_EQ(solution_.theMaximumAchievableX(4, 1), 6);
}

TEST_P(FindTheMaximumAchievableNumberTest, Example2) {
  EXPECT_EQ(solution_.theMaximumAchievableX(3, 2), 7);
}

TEST_P(FindTheMaximumAchievableNumberTest, SelfAuthoredMin) {
  EXPECT_EQ(solution_.theMaximumAchievableX(1, 1), 3);
}

TEST_P(FindTheMaximumAchievableNumberTest, SelfAuthoredMax) {
  EXPECT_EQ(solution_.theMaximumAchievableX(50, 50), 150);
}

TEST_P(FindTheMaximumAchievableNumberTest, SelfAuthoredZeroT) {
  EXPECT_EQ(solution_.theMaximumAchievableX(10, 1), 12);
}

INSTANTIATE_TEST_SUITE_P(
    FindTheMaximumAchievableNumberTestSuite,
    FindTheMaximumAchievableNumberTest,
    ::testing::ValuesIn(FindTheMaximumAchievableNumberSolution().getStrategyNames()));

}  // namespace leetcode::problem_2769
