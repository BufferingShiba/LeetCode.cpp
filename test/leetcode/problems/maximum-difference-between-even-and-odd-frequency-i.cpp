#include <gtest/gtest.h>

#include "leetcode/problems/maximum-difference-between-even-and-odd-frequency-i.h"

using namespace leetcode::problem_3442;

class MaximumDifferenceBetweenEvenAndOddFrequencyITest : public ::testing::TestWithParam<std::string> {
 protected:
  MaximumDifferenceBetweenEvenAndOddFrequencyISolution solution;

  void SetUp() override {
    solution.setStrategy(GetParam());
  }
};

TEST_P(MaximumDifferenceBetweenEvenAndOddFrequencyITest, Example1) {
  EXPECT_EQ(solution.maxDifference("aaaaabbc"), 3);
}

TEST_P(MaximumDifferenceBetweenEvenAndOddFrequencyITest, Example2) {
  EXPECT_EQ(solution.maxDifference("abcabcab"), 1);
}

TEST_P(MaximumDifferenceBetweenEvenAndOddFrequencyITest, SelfAuthoredSmallCase) {
  // a=3(odd), b=2(even) → 3 - 2 = 1
  EXPECT_EQ(solution.maxDifference("aaabb"), 1);
}

TEST_P(MaximumDifferenceBetweenEvenAndOddFrequencyITest, SelfAuthoredEvenLargerThanOdd) {
  // a=2(even), b=1(odd) → 1 - 2 = -1
  EXPECT_EQ(solution.maxDifference("aab"), -1);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    MaximumDifferenceBetweenEvenAndOddFrequencyITest,
    ::testing::ValuesIn(MaximumDifferenceBetweenEvenAndOddFrequencyISolution().getStrategyNames()));
