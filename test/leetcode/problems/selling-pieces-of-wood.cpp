#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/selling-pieces-of-wood.h"

namespace leetcode::problem_2312 {

class SellingPiecesOfWoodTest : public ::testing::TestWithParam<std::string> {
protected:
    SellingPiecesOfWoodSolution solution;

    void SetUp() override {
        solution.setStrategy(GetParam());
    }
};

TEST_P(SellingPiecesOfWoodTest, Example1) {
    int m = 3, n = 5;
    std::vector<std::vector<int>> prices = {{1, 4, 2}, {2, 2, 7}, {2, 1, 3}};
    EXPECT_EQ(19, solution.sellingWood(m, n, prices));
}

TEST_P(SellingPiecesOfWoodTest, Example2) {
    int m = 4, n = 6;
    std::vector<std::vector<int>> prices = {{3, 2, 10}, {1, 4, 2}, {4, 1, 3}};
    EXPECT_EQ(32, solution.sellingWood(m, n, prices));
}

TEST_P(SellingPiecesOfWoodTest, SelfAuthoredSinglePiece) {
    int m = 2, n = 2;
    std::vector<std::vector<int>> prices = {{2, 2, 100}};
    EXPECT_EQ(100, solution.sellingWood(m, n, prices));
}

TEST_P(SellingPiecesOfWoodTest, SelfAuthoredSquareSizeOne) {
    int m = 1, n = 1;
    std::vector<std::vector<int>> prices = {{1, 1, 5}};
    EXPECT_EQ(5, solution.sellingWood(m, n, prices));
}

TEST_P(SellingPiecesOfWoodTest, SelfAuthoredCostlyCuttingSkips) {
    // Selling 1x1 for 1 each; a 2x2 only listed at price 3 (< 4 by four small),
    // so cutting into small squares is better.
    int m = 2, n = 2;
    std::vector<std::vector<int>> prices = {{1, 1, 1}, {2, 2, 3}};
    EXPECT_EQ(4, solution.sellingWood(m, n, prices));
}

INSTANTIATE_TEST_SUITE_P(
    SellingPiecesOfWoodTestSuites,
    SellingPiecesOfWoodTest,
    ::testing::ValuesIn(SellingPiecesOfWoodSolution().getStrategyNames()));

}  // namespace leetcode::problem_2312
