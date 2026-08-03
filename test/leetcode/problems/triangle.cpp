#include <gtest/gtest.h>
#include "leetcode/problems/triangle.h"

using namespace leetcode::problem_120;

class TriangleTest : public ::testing::TestWithParam<std::string> {
protected:
    TriangleSolution solution;
    void SetUp() override {
        solution.setStrategy(GetParam());
    }
};

TEST_P(TriangleTest, Example1) {
    std::vector<std::vector<int>> triangle = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
    EXPECT_EQ(solution.minimumTotal(triangle), 11);
}

TEST_P(TriangleTest, Example2) {
    std::vector<std::vector<int>> triangle = {{-10}};
    EXPECT_EQ(solution.minimumTotal(triangle), -10);
}

TEST_P(TriangleTest, SelfAuthoredSingleRow) {
    std::vector<std::vector<int>> triangle = {{5}};
    EXPECT_EQ(solution.minimumTotal(triangle), 5);
}

TEST_P(TriangleTest, SelfAuthoredNegativePath) {
    std::vector<std::vector<int>> triangle = {{1}, {-2, -5}, {3, 6, 1}};
    // Path: 1 -> -5 -> 1 = -3
    EXPECT_EQ(solution.minimumTotal(triangle), -3);
}

INSTANTIATE_TEST_SUITE_P(
    TriangleStrategies,
    TriangleTest,
    ::testing::ValuesIn(TriangleSolution().getStrategyNames())
);
