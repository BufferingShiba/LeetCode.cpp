#include <gtest/gtest.h>

#include "leetcode/problems/compare-version-numbers.h"

using leetcode::problem_165::CompareVersionNumbersSolution;

namespace leetcode::problem_165 {

class CompareVersionNumbersTest : public ::testing::TestWithParam<std::string> {
protected:
    void SetUp() override {
        solution.setStrategy(GetParam());
    }

    CompareVersionNumbersSolution solution;
};

TEST_P(CompareVersionNumbersTest, Example1) {
    EXPECT_EQ(solution.getSolution()("1.2", "1.10"), -1);
}

TEST_P(CompareVersionNumbersTest, Example2) {
    EXPECT_EQ(solution.getSolution()("1.01", "1.001"), 0);
}

TEST_P(CompareVersionNumbersTest, Example3) {
    EXPECT_EQ(solution.getSolution()("1.0", "1.0.0.0"), 0);
}

TEST_P(CompareVersionNumbersTest, SelfAuthoredVersion2Greater) {
    EXPECT_EQ(solution.getSolution()("0.1", "1.1"), -1);
}

TEST_P(CompareVersionNumbersTest, SelfAuthoredVersion1Greater) {
    EXPECT_EQ(solution.getSolution()("1.0.1", "1"), 1);
}

TEST_P(CompareVersionNumbersTest, SelfAuthoredEqualNoDots) {
    EXPECT_EQ(solution.getSolution()("7", "7"), 0);
}

TEST_P(CompareVersionNumbersTest, SelfAuthoredMissingRevisionsAsZero) {
    EXPECT_EQ(solution.getSolution()("1.1", "1.1.0.0"), 0);
}

INSTANTIATE_TEST_SUITE_P(
    CompareVersionNumbersTestSuite,
    CompareVersionNumbersTest,
    ::testing::ValuesIn(CompareVersionNumbersSolution().getStrategyNames()));

}  // namespace leetcode::problem_165
