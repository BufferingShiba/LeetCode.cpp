#include <gtest/gtest.h>

#include <vector>
#include <string>

#include "leetcode/problems/maximum-number-of-non-overlapping-palindrome-substrings.h"

namespace leetcode {
namespace problem_2472 {

class MaximumNumberOfNonOverlappingPalindromeSubstringsTest
    : public ::testing::TestWithParam<std::string> {
protected:
    MaximumNumberOfNonOverlappingPalindromeSubstringsSolution solution;

    void SetUp() override {
        solution.setStrategy(GetParam());
    }
};

TEST_P(MaximumNumberOfNonOverlappingPalindromeSubstringsTest, Example1) {
    EXPECT_EQ(solution.maxPalindromes("abaccdbbd", 3), 2);
}

TEST_P(MaximumNumberOfNonOverlappingPalindromeSubstringsTest, Example2) {
    EXPECT_EQ(solution.maxPalindromes("adbcda", 2), 0);
}

TEST_P(MaximumNumberOfNonOverlappingPalindromeSubstringsTest, SelfAuthoredSingleCharK1) {
    EXPECT_EQ(solution.maxPalindromes("a", 1), 1);
}

TEST_P(MaximumNumberOfNonOverlappingPalindromeSubstringsTest, SelfAuthoredAllSameSingleLetter) {
    EXPECT_EQ(solution.maxPalindromes("aaaaa", 2), 2);
}

TEST_P(MaximumNumberOfNonOverlappingPalindromeSubstringsTest, SelfAuthoredNoValidK2SingleChar) {
    EXPECT_EQ(solution.maxPalindromes("a", 2), 0);
}

TEST_P(MaximumNumberOfNonOverlappingPalindromeSubstringsTest, SelfAuthoredTwoSingleCharsK1) {
    EXPECT_EQ(solution.maxPalindromes("ab", 1), 2);
}

INSTANTIATE_TEST_SUITE_P(
    MaximumNumberOfNonOverlappingPalindromeSubstringsTest,
    MaximumNumberOfNonOverlappingPalindromeSubstringsTest,
    ::testing::ValuesIn(MaximumNumberOfNonOverlappingPalindromeSubstringsSolution().getStrategyNames()));

}  // namespace problem_2472
}  // namespace leetcode
