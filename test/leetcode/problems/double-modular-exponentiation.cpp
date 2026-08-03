#include <gtest/gtest.h>

#include "leetcode/problems/double-modular-exponentiation.h"

namespace leetcode::problem_2961 {
namespace {

class DoubleModularExponentiationTest
    : public ::testing::TestWithParam<std::string> {
protected:
    void SetUp() override { solution_.setStrategy(GetParam()); }

    DoubleModularExponentiationSolution solution_;
};

TEST_P(DoubleModularExponentiationTest, Example1) {
    std::vector<std::vector<int>> variables = {{2, 3, 3, 10},
                                               {3, 3, 3, 1},
                                               {6, 1, 1, 4}};
    std::vector<int> expected = {0, 2};
    EXPECT_EQ(solution_.getGoodIndices(variables, 2), expected);
}

TEST_P(DoubleModularExponentiationTest, Example2) {
    std::vector<std::vector<int>> variables = {{39, 3, 1000, 1000}};
    std::vector<int> expected = {};
    EXPECT_EQ(solution_.getGoodIndices(variables, 17), expected);
}

TEST_P(DoubleModularExponentiationTest, ModOneAlwaysZero) {
    // mod == 1 makes every value 0, so all indices match target = 0.
    std::vector<std::vector<int>> variables = {{7, 5, 3, 1}, {1, 1, 1, 1}};
    std::vector<int> expected = {0, 1};
    EXPECT_EQ(solution_.getGoodIndices(variables, 0), expected);
}

TEST_P(DoubleModularExponentiationTest, SingleMaxValue) {
    // a=1000, b=1000, c=1000, m=1000. (1000^1000 % 10) = 0; 0^1000 % 1000 = 0.
    std::vector<std::vector<int>> variables = {{1000, 1000, 1000, 1000}};
    std::vector<int> expected = {0};
    EXPECT_EQ(solution_.getGoodIndices(variables, 0), expected);
}

INSTANTIATE_TEST_SUITE_P(
    DoubleModularExponentiationTestSuite, DoubleModularExponentiationTest,
    ::testing::ValuesIn(DoubleModularExponentiationSolution().getStrategyNames()));

}  // namespace
}  // namespace leetcode::problem_2961
