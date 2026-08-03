#include <gtest/gtest.h>
#include "leetcode/problems/minimum-swaps-to-make-strings-equal.h"

using namespace leetcode::problem_1247;

class MinimumSwapsToMakeStringsEqualTest : public ::testing::TestWithParam<std::string> {
protected:
    MinimumSwapsToMakeStringsEqualSolution solution;

    void SetUp() override {
        solution.setStrategy(GetParam());
    }
};

TEST_P(MinimumSwapsToMakeStringsEqualTest, Examples) {
    EXPECT_EQ(solution.minimumSwap("xx", "yy"), 1);
    EXPECT_EQ(solution.minimumSwap("xy", "yx"), 2);
    EXPECT_EQ(solution.minimumSwap("xx", "xy"), -1);
}

TEST_P(MinimumSwapsToMakeStringsEqualTest, AlreadyEqual) {
    EXPECT_EQ(solution.minimumSwap("xy", "xy"), 0);
    EXPECT_EQ(solution.minimumSwap("x", "x"), 0);
    EXPECT_EQ(solution.minimumSwap("y", "y"), 0);
}

TEST_P(MinimumSwapsToMakeStringsEqualTest, AllMismatchSameType) {
    // s1 = "xxxx", s2 = "yyyy" → 4 xy, 0 yx → 4/2 = 2 swaps
    EXPECT_EQ(solution.minimumSwap("xxxx", "yyyy"), 2);
    // s1 = "yyyy", s2 = "xxxx" → 0 xy, 4 yx → 4/2 = 2 swaps
    EXPECT_EQ(solution.minimumSwap("yyyy", "xxxx"), 2);
}

TEST_P(MinimumSwapsToMakeStringsEqualTest, SelfAuthoredMixedMismatch) {
    // s1 = "xxxy", s2 = "yyyx" → xy=3, yx=1 → 3/2 + 1/2 + 2 = 1 + 0 + 2 = 3
    EXPECT_EQ(solution.minimumSwap("xxxy", "yyyx"), 3);
    // s1 = "xxyy", s2 = "yyxx" → xy=2, yx=2 → 1+1+0 = 2
    EXPECT_EQ(solution.minimumSwap("xxyy", "yyxx"), 2);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    MinimumSwapsToMakeStringsEqualTest,
    ::testing::ValuesIn(MinimumSwapsToMakeStringsEqualSolution().getStrategyNames())
);
