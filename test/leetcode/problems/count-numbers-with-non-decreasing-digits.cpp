#include <gtest/gtest.h>
#include "leetcode/problems/count-numbers-with-non-decreasing-digits.h"

using namespace leetcode::problem_3519;

class CountNumbersWithNonDecreasingDigitsTest : public ::testing::TestWithParam<std::string> {
 protected:
    CountNumbersWithNonDecreasingDigitsSolution solution;

    void SetUp() override {
        solution.setStrategy(GetParam());
    }
};

TEST_P(CountNumbersWithNonDecreasingDigitsTest, Example1) {
    EXPECT_EQ(solution.countNumbers("23", "28", 8), 3);
}

TEST_P(CountNumbersWithNonDecreasingDigitsTest, Example2) {
    EXPECT_EQ(solution.countNumbers("2", "7", 2), 2);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    CountNumbersWithNonDecreasingDigitsTest,
    ::testing::ValuesIn(CountNumbersWithNonDecreasingDigitsSolution().getStrategyNames()));
