#include <gtest/gtest.h>

#include "leetcode/problems/execution-of-all-suffix-instructions-staying-in-a-grid.h"

using namespace leetcode::problem_2120;

class ExecutionOfAllSuffixInstructionsStayingInAGridTest
    : public ::testing::TestWithParam<std::string> {
 protected:
    ExecutionOfAllSuffixInstructionsStayingInAGridSolution solution;

    void SetUp() override { solution.setStrategy(GetParam()); }
};

TEST_P(ExecutionOfAllSuffixInstructionsStayingInAGridTest, Example1) {
    int n = 3;
    std::vector<int> startPos = {0, 1};
    std::string s = "RRDDLU";
    std::vector<int> expected = {1, 5, 4, 3, 1, 0};
    EXPECT_EQ(solution.executeInstructions(n, startPos, s), expected);
}

TEST_P(ExecutionOfAllSuffixInstructionsStayingInAGridTest, Example2) {
    int n = 2;
    std::vector<int> startPos = {1, 1};
    std::string s = "LURD";
    std::vector<int> expected = {4, 1, 0, 0};
    EXPECT_EQ(solution.executeInstructions(n, startPos, s), expected);
}

TEST_P(ExecutionOfAllSuffixInstructionsStayingInAGridTest, Example3) {
    int n = 1;
    std::vector<int> startPos = {0, 0};
    std::string s = "LRUD";
    std::vector<int> expected = {0, 0, 0, 0};
    EXPECT_EQ(solution.executeInstructions(n, startPos, s), expected);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    ExecutionOfAllSuffixInstructionsStayingInAGridTest,
    ::testing::ValuesIn(
        ExecutionOfAllSuffixInstructionsStayingInAGridSolution().getStrategyNames()));
