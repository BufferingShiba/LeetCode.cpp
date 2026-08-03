#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/minimum-insertions-to-balance-a-parentheses-string.h"

namespace leetcode::problem_1541 {

class MinimumInsertionsToBalanceAParenthesesStringTest : public ::testing::TestWithParam<std::string> {
protected:
    MinimumInsertionsToBalanceAParenthesesStringSolution solution;

    void SetUp() override {
        solution.setStrategy(GetParam());
    }
};

TEST_P(MinimumInsertionsToBalanceAParenthesesStringTest, Example1) {
    ASSERT_EQ(solution.minInsertions("(()))"), 1);
}

TEST_P(MinimumInsertionsToBalanceAParenthesesStringTest, Example2) {
    ASSERT_EQ(solution.minInsertions("())"), 0);
}

TEST_P(MinimumInsertionsToBalanceAParenthesesStringTest, Example3) {
    ASSERT_EQ(solution.minInsertions("))())("), 3);
}

TEST_P(MinimumInsertionsToBalanceAParenthesesStringTest, SingleLeft) {
    ASSERT_EQ(solution.minInsertions("("), 2);
}

TEST_P(MinimumInsertionsToBalanceAParenthesesStringTest, SingleRight) {
    ASSERT_EQ(solution.minInsertions(")"), 2);
}

TEST_P(MinimumInsertionsToBalanceAParenthesesStringTest, TwoRights) {
    ASSERT_EQ(solution.minInsertions("))"), 1);
}

TEST_P(MinimumInsertionsToBalanceAParenthesesStringTest, AllLefts) {
    ASSERT_EQ(solution.minInsertions("((("), 6);
}

INSTANTIATE_TEST_SUITE_P(
    MinimumInsertionsToBalanceAParenthesesStringTestCases,
    MinimumInsertionsToBalanceAParenthesesStringTest,
    ::testing::ValuesIn(
        MinimumInsertionsToBalanceAParenthesesStringSolution().getStrategyNames()));

}  // namespace leetcode::problem_1541
