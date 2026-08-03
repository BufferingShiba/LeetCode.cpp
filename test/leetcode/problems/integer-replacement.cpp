#include <gtest/gtest.h>
#include "leetcode/problems/integer-replacement.h"
#include <string>
#include <vector>

namespace leetcode::problem_397 {

class IntegerReplacementTest : public ::testing::TestWithParam<std::string> {
protected:
    void SetUp() override {
        solution.setStrategy(GetParam());
    }

    IntegerReplacementSolution solution;
};

TEST_P(IntegerReplacementTest, Example1) {
    EXPECT_EQ(solution.integerReplacement(8), 3);
}

TEST_P(IntegerReplacementTest, Example2) {
    EXPECT_EQ(solution.integerReplacement(7), 4);
}

TEST_P(IntegerReplacementTest, Example3) {
    EXPECT_EQ(solution.integerReplacement(4), 2);
}

TEST_P(IntegerReplacementTest, SelfAuthoredEdgeCase_N1) {
    EXPECT_EQ(solution.integerReplacement(1), 0);
}

TEST_P(IntegerReplacementTest, SelfAuthoredEdgeCase_N2) {
    EXPECT_EQ(solution.integerReplacement(2), 1);
}

TEST_P(IntegerReplacementTest, SelfAuthoredEdgeCase_N3) {
    EXPECT_EQ(solution.integerReplacement(3), 2);
}

TEST_P(IntegerReplacementTest, SelfAuthoredEdgeCase_N6) {
    // 6 -> 3 -> 2 -> 1 (3 steps)
    EXPECT_EQ(solution.integerReplacement(6), 3);
}

TEST_P(IntegerReplacementTest, SelfAuthoredEdgeCase_N10) {
    // 10 -> 5 -> 4 -> 2 -> 1 (4 steps)
    EXPECT_EQ(solution.integerReplacement(10), 4);
}

TEST_P(IntegerReplacementTest, SelfAuthoredEdgeCase_MaxInt) {
    // 2^31 - 1
    EXPECT_EQ(solution.integerReplacement(2147483647), 32);
}

INSTANTIATE_TEST_SUITE_P(
    IntegerReplacementParam,
    IntegerReplacementTest,
    ::testing::ValuesIn(IntegerReplacementSolution().getStrategyNames()));

}  // namespace leetcode::problem_397
