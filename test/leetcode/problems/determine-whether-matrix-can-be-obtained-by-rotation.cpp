#include <gtest/gtest.h>

#include "leetcode/problems/determine-whether-matrix-can-be-obtained-by-rotation.h"

#include <string>
#include <vector>

namespace leetcode::problem_1886 {

class DetermineWhetherMatrixCanBeObtainedByRotationTest
    : public ::testing::TestWithParam<std::string> {
protected:
    void SetUp() override {
        solution.setStrategy(GetParam());
    }

    DetermineWhetherMatrixCanBeObtainedByRotationSolution solution;
};

TEST_P(DetermineWhetherMatrixCanBeObtainedByRotationTest, Example1) {
    std::vector<std::vector<int>> mat = {{0, 1}, {1, 0}};
    std::vector<std::vector<int>> target = {{1, 0}, {0, 1}};
    EXPECT_TRUE(solution.findRotation(mat, target));
}

TEST_P(DetermineWhetherMatrixCanBeObtainedByRotationTest, Example2) {
    std::vector<std::vector<int>> mat = {{0, 1}, {1, 1}};
    std::vector<std::vector<int>> target = {{1, 0}, {0, 1}};
    EXPECT_FALSE(solution.findRotation(mat, target));
}

TEST_P(DetermineWhetherMatrixCanBeObtainedByRotationTest, Example3) {
    std::vector<std::vector<int>> mat = {{0, 0, 0}, {0, 1, 0}, {1, 1, 1}};
    std::vector<std::vector<int>> target = {{1, 1, 1}, {0, 1, 0}, {0, 0, 0}};
    EXPECT_TRUE(solution.findRotation(mat, target));
}

TEST_P(DetermineWhetherMatrixCanBeObtainedByRotationTest, SelfAuthoredSameMatrixZeroRotation) {
    std::vector<std::vector<int>> mat = {{1, 0}, {0, 1}};
    std::vector<std::vector<int>> target = {{1, 0}, {0, 1}};
    EXPECT_TRUE(solution.findRotation(mat, target));
}

TEST_P(DetermineWhetherMatrixCanBeObtainedByRotationTest, SelfAuthoredSingleElement) {
    std::vector<std::vector<int>> mat = {{1}};
    std::vector<std::vector<int>> target = {{1}};
    EXPECT_TRUE(solution.findRotation(mat, target));
}

TEST_P(DetermineWhetherMatrixCanBeObtainedByRotationTest, SelfAuthoredSingleElementMismatch) {
    std::vector<std::vector<int>> mat = {{1}};
    std::vector<std::vector<int>> target = {{0}};
    EXPECT_FALSE(solution.findRotation(mat, target));
}

INSTANTIATE_TEST_SUITE_P(
    DetermineWhetherMatrixCanBeObtainedByRotationTestCases,
    DetermineWhetherMatrixCanBeObtainedByRotationTest,
    ::testing::ValuesIn(
        DetermineWhetherMatrixCanBeObtainedByRotationSolution().getStrategyNames()));

}  // namespace leetcode::problem_1886
