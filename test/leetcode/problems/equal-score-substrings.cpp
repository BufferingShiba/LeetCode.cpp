#include <string>

#include <gtest/gtest.h>

#include "leetcode/problems/equal-score-substrings.h"

namespace leetcode::problem_3707 {

class EqualScoreSubstringsTest
    : public ::testing::TestWithParam<std::string> {
protected:
    void SetUp() override { solution_.setStrategy(GetParam()); }

    EqualScoreSubstringsSolution solution_;
};

TEST_P(EqualScoreSubstringsTest, Example1) {
    EXPECT_TRUE(solution_.scoreBalance("adcb"));
}

TEST_P(EqualScoreSubstringsTest, Example2) {
    EXPECT_FALSE(solution_.scoreBalance("bace"));
}

TEST_P(EqualScoreSubstringsTest, SelfAuthoredSplitMiddle) {
    // "aa": total = 2, split at index 0 -> left 1, right 1.
    EXPECT_TRUE(solution_.scoreBalance("aa"));
}

TEST_P(EqualScoreSubstringsTest, SelfAuthoredBalancedPair) {
    // "abba": total = 1+2+2+1 = 6, split at index 1 -> left 3, right 3.
    EXPECT_TRUE(solution_.scoreBalance("abba"));
}

TEST_P(EqualScoreSubstringsTest, SelfAuthoredAllSame) {
    // "bb": total = 4, split at index 0 -> left 2, right 2.
    EXPECT_TRUE(solution_.scoreBalance("bb"));
}

INSTANTIATE_TEST_SUITE_P(
    EqualScoreSubstringsParam, EqualScoreSubstringsTest,
    ::testing::ValuesIn(EqualScoreSubstringsSolution().getStrategyNames()));

}  // namespace leetcode::problem_3707
