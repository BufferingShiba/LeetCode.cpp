#include <gtest/gtest.h>
#include "leetcode/problems/faulty-keyboard.h"

using namespace leetcode::problem_2810;

class FaultyKeyboardTest : public ::testing::TestWithParam<std::string> {
 protected:
    FaultyKeyboardSolution solution;

    void SetUp() override {
        solution.setStrategy(GetParam());
    }
};

TEST_P(FaultyKeyboardTest, Example1) {
    EXPECT_EQ(solution.finalString("string"), "rtsng");
}

TEST_P(FaultyKeyboardTest, Example2) {
    EXPECT_EQ(solution.finalString("poiinter"), "ponter");
}

TEST_P(FaultyKeyboardTest, SelfAuthoredNoI) {
    EXPECT_EQ(solution.finalString("abc"), "abc");
}

TEST_P(FaultyKeyboardTest, SelfAuthoredSingleIAtEnd) {
    // "abci" → after typing 'a','b','c' we have "abc", then 'i' reverses to "cba"
    EXPECT_EQ(solution.finalString("abci"), "cba");
}

TEST_P(FaultyKeyboardTest, SelfAuthoredMultipleReversals) {
    // "abiic" → a → ab → i reverse → "ba" → i reverse → "ab" → c → "abc"
    EXPECT_EQ(solution.finalString("abiic"), "abc");
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    FaultyKeyboardTest,
    ::testing::ValuesIn(FaultyKeyboardSolution().getStrategyNames())
);
