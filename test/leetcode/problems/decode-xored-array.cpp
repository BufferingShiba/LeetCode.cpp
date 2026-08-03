#include "leetcode/problems/decode-xored-array.h"

#include <gtest/gtest.h>
#include <string>
#include <vector>

namespace leetcode::problem_1720 {

class DecodeXoredArrayTest : public ::testing::TestWithParam<std::string> {
protected:
    void SetUp() override {
        solution.setStrategy(GetParam());
    }

    DecodeXoredArraySolution solution;
};

TEST_P(DecodeXoredArrayTest, Example1) {
    std::vector<int> encoded{1, 2, 3};
    int first = 1;
    std::vector<int> expected{1, 0, 2, 1};
    EXPECT_EQ(expected, solution.decode(encoded, first));
}

TEST_P(DecodeXoredArrayTest, Example2) {
    std::vector<int> encoded{6, 2, 7, 3};
    int first = 4;
    std::vector<int> expected{4, 2, 0, 7, 4};
    EXPECT_EQ(expected, solution.decode(encoded, first));
}

TEST_P(DecodeXoredArrayTest, SelfAuthoredSingleElement) {
    std::vector<int> encoded{5};
    int first = 5;
    std::vector<int> expected{5, 0};
    EXPECT_EQ(expected, solution.decode(encoded, first));
}

TEST_P(DecodeXoredArrayTest, SelfAuthoredZeroFirst) {
    std::vector<int> encoded{3, 10, 7};
    int first = 0;
    std::vector<int> expected{0, 3, 9, 14};
    EXPECT_EQ(expected, solution.decode(encoded, first));
}

INSTANTIATE_TEST_SUITE_P(
    DecodeXoredArrayTestSuite,
    DecodeXoredArrayTest,
    ::testing::ValuesIn(DecodeXoredArraySolution().getStrategyNames()));

}  // namespace leetcode::problem_1720
