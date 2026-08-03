#include <gtest/gtest.h>

#include <string>

#include "leetcode/problems/digit-frequency-score.h"

namespace leetcode::problem_3945 {

class DigitFrequencyScoreTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  DigitFrequencyScoreSolution solution;
};

TEST_P(DigitFrequencyScoreTest, Example1) {
  EXPECT_EQ(solution.digitFrequencyScore(122), 5);
}

TEST_P(DigitFrequencyScoreTest, Example2) {
  EXPECT_EQ(solution.digitFrequencyScore(101), 2);
}

TEST_P(DigitFrequencyScoreTest, SelfAuthoredSingleDigit) {
  // n = 7, digit 7 appears once: 7 * 1 = 7
  EXPECT_EQ(solution.digitFrequencyScore(7), 7);
}

TEST_P(DigitFrequencyScoreTest, SelfAuthoredRepeatedSameDigit) {
  // n = 222, digit 2 appears 3 times: 2 * 3 = 6
  EXPECT_EQ(solution.digitFrequencyScore(222), 6);
}

INSTANTIATE_TEST_SUITE_P(
    DigitFrequencyScoreTestSuite, DigitFrequencyScoreTest,
    ::testing::ValuesIn(DigitFrequencyScoreSolution().getStrategyNames()));

}  // namespace leetcode::problem_3945
