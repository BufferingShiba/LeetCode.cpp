#include <gtest/gtest.h>

#include "leetcode/problems/remove-colored-pieces-if-both-neighbors-are-the-same-color.h"

using namespace leetcode::problem_2038;

class RemoveColoredPiecesIfBothNeighborsAreTheSameColorTest
    : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override {
    solution.setStrategy(GetParam());
  }
  RemoveColoredPiecesIfBothNeighborsAreTheSameColorSolution solution;
};

TEST_P(RemoveColoredPiecesIfBothNeighborsAreTheSameColorTest, Example1) {
  EXPECT_TRUE(solution.winnerOfGame("AAABABB"));
}

TEST_P(RemoveColoredPiecesIfBothNeighborsAreTheSameColorTest, Example2) {
  EXPECT_FALSE(solution.winnerOfGame("AA"));
}

TEST_P(RemoveColoredPiecesIfBothNeighborsAreTheSameColorTest, Example3) {
  EXPECT_FALSE(solution.winnerOfGame("ABBBBBBBAAA"));
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    RemoveColoredPiecesIfBothNeighborsAreTheSameColorTest,
    testing::ValuesIn(
        RemoveColoredPiecesIfBothNeighborsAreTheSameColorSolution()
            .getStrategyNames()));
