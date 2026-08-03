#include <gtest/gtest.h>

#include "leetcode/problems/count-substrings-divisible-by-last-digit.h"

namespace leetcode::problem_3448 {

class CountSubstringsDivisibleByLastDigitTest : public ::testing::TestWithParam<std::string> {
 protected:
    CountSubstringsDivisibleByLastDigitSolution solution;

    void SetUp() override {
        solution.setStrategy(GetParam());
    }
};

TEST_P(CountSubstringsDivisibleByLastDigitTest, Example1) {
    EXPECT_EQ(solution.countSubstrings("12936"), 11);
}

TEST_P(CountSubstringsDivisibleByLastDigitTest, Example2) {
    EXPECT_EQ(solution.countSubstrings("5701283"), 18);
}

TEST_P(CountSubstringsDivisibleByLastDigitTest, Example3) {
    EXPECT_EQ(solution.countSubstrings("1010101010"), 25);
}

TEST_P(CountSubstringsDivisibleByLastDigitTest, EdgeCases) {
    // Single non-zero digit
    EXPECT_EQ(solution.countSubstrings("5"), 1);
    // Single zero
    EXPECT_EQ(solution.countSubstrings("0"), 0);
    // "10": only "1" counts
    EXPECT_EQ(solution.countSubstrings("10"), 1);
    // "101": "1", "01", "101", and the last "1" → 4
    EXPECT_EQ(solution.countSubstrings("101"), 4);
    // All zeros
    EXPECT_EQ(solution.countSubstrings("000"), 0);
    // Mixed with leading zeros: "0","0","00","1","01","001","2","12","012","0012"
    // All ending at '1' or '2' are divisible → 3 + 4 = 7
    EXPECT_EQ(solution.countSubstrings("0012"), 7);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    CountSubstringsDivisibleByLastDigitTest,
    ::testing::ValuesIn(CountSubstringsDivisibleByLastDigitSolution().getStrategyNames()));

}  // namespace leetcode::problem_3448
