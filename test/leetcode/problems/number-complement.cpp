#include <gtest/gtest.h>
#include "leetcode/problems/number-complement.h"
#include <string>
#include <vector>

namespace leetcode {
namespace problem_476 {
namespace {

class NumberComplementTest : public ::testing::TestWithParam<std::string> {
protected:
    NumberComplementSolution solution;

    void SetUp() override {
        solution.setStrategy(GetParam());
    }
};

TEST_P(NumberComplementTest, Example1) {
    EXPECT_EQ(solution.findComplement(5), 2);
}

TEST_P(NumberComplementTest, Example2) {
    EXPECT_EQ(solution.findComplement(1), 0);
}

TEST_P(NumberComplementTest, SelfAuthoredCase1) {
    // 2 -> 10 -> 01 = 1
    EXPECT_EQ(solution.findComplement(2), 1);
}

TEST_P(NumberComplementTest, SelfAuthoredCase2) {
    // 7 -> 111 -> 000 = 0
    EXPECT_EQ(solution.findComplement(7), 0);
}

TEST_P(NumberComplementTest, SelfAuthoredCase3) {
    // 10 -> 1010 -> 0101 = 5
    EXPECT_EQ(solution.findComplement(10), 5);
}

INSTANTIATE_TEST_SUITE_P(
    NumberComplementTestSuite,
    NumberComplementTest,
    ::testing::ValuesIn(NumberComplementSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_476
}  // namespace leetcode
