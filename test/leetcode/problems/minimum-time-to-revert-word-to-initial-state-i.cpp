#include <gtest/gtest.h>

#include <string>

#include "leetcode/problems/minimum-time-to-revert-word-to-initial-state-i.h"

using leetcode::problem_3029::MinimumTimeToRevertWordToInitialStateISolution;

class MinimumTimeToRevertWordToInitialStateITest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override {
    solution_.setStrategy(GetParam());
  }

  MinimumTimeToRevertWordToInitialStateISolution solution_;
};

TEST_P(MinimumTimeToRevertWordToInitialStateITest, Example1) {
  EXPECT_EQ(solution_.minimumTimeToInitialState("abacaba", 3), 2);
}

TEST_P(MinimumTimeToRevertWordToInitialStateITest, Example2) {
  EXPECT_EQ(solution_.minimumTimeToInitialState("abacaba", 4), 1);
}

TEST_P(MinimumTimeToRevertWordToInitialStateITest, Example3) {
  EXPECT_EQ(solution_.minimumTimeToInitialState("abcbabcd", 2), 4);
}

TEST_P(MinimumTimeToRevertWordToInitialStateITest, SelfAuthoredSingleChar) {
  EXPECT_EQ(solution_.minimumTimeToInitialState("a", 1), 1);
}

TEST_P(MinimumTimeToRevertWordToInitialStateITest, SelfAuthoredKEqualsLength) {
  EXPECT_EQ(solution_.minimumTimeToInitialState("abc", 3), 1);
}

TEST_P(MinimumTimeToRevertWordToInitialStateITest, SelfAuthoredRepeatedChar) {
  EXPECT_EQ(solution_.minimumTimeToInitialState("aaaa", 2), 1);
}

INSTANTIATE_TEST_SUITE_P(
    MinimumTimeToRevertWordToInitialStateITestSuite,
    MinimumTimeToRevertWordToInitialStateITest,
    ::testing::ValuesIn(
        MinimumTimeToRevertWordToInitialStateISolution().getStrategyNames()));
