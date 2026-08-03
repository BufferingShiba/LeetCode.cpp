#include <gtest/gtest.h>

#include "leetcode/problems/number-of-dice-rolls-with-target-sum.h"

namespace leetcode {
namespace problem_1155 {

class NumberOfDiceRollsWithTargetSumTest
    : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  NumberOfDiceRollsWithTargetSumSolution solution_;
};

TEST_P(NumberOfDiceRollsWithTargetSumTest, Example1) {
  EXPECT_EQ(solution_.numRollsToTarget(1, 6, 3), 1);
}

TEST_P(NumberOfDiceRollsWithTargetSumTest, Example2) {
  EXPECT_EQ(solution_.numRollsToTarget(2, 6, 7), 6);
}

TEST_P(NumberOfDiceRollsWithTargetSumTest, Example3) {
  EXPECT_EQ(solution_.numRollsToTarget(30, 30, 500), 222616187);
}

TEST_P(NumberOfDiceRollsWithTargetSumTest, SelfAuthoredTargetTooSmall) {
  // n=3 dice, minimum sum is 3, so target=2 is impossible.
  EXPECT_EQ(solution_.numRollsToTarget(3, 6, 2), 0);
}

TEST_P(NumberOfDiceRollsWithTargetSumTest, SelfAuthoredTargetTooLarge) {
  // n=2 dice with k=4, max sum is 8, so target=10 is impossible.
  EXPECT_EQ(solution_.numRollsToTarget(2, 4, 10), 0);
}

TEST_P(NumberOfDiceRollsWithTargetSumTest, SelfAuthoredSingleDieAllFaces) {
  // 1 die, k=5, target=3: only one way (face 3).
  EXPECT_EQ(solution_.numRollsToTarget(1, 5, 3), 1);
}

TEST_P(NumberOfDiceRollsWithTargetSumTest, SelfAuthoredAllOnes) {
  // n=4 dice, k=6, target=4: only one way (all ones).
  EXPECT_EQ(solution_.numRollsToTarget(4, 6, 4), 1);
}

TEST_P(NumberOfDiceRollsWithTargetSumTest, SelfAuthoredAllMaxFaces) {
  // n=3 dice, k=5, target=15: only one way (all fives).
  EXPECT_EQ(solution_.numRollsToTarget(3, 5, 15), 1);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    NumberOfDiceRollsWithTargetSumTest,
    testing::ValuesIn(
        NumberOfDiceRollsWithTargetSumSolution().getStrategyNames()));

}  // namespace problem_1155
}  // namespace leetcode
