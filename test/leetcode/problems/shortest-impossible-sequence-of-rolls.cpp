#include <gtest/gtest.h>

#include "leetcode/problems/shortest-impossible-sequence-of-rolls.h"

namespace leetcode {
namespace problem_2350 {

class ShortestImpossibleSequenceOfRollsTest
    : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }
  ShortestImpossibleSequenceOfRollsSolution solution;
};

TEST_P(ShortestImpossibleSequenceOfRollsTest, Example1) {
  std::vector<int> rolls = {4, 2, 1, 2, 3, 3, 2, 4, 1};
  int k = 4;
  EXPECT_EQ(solution.shortestSequence(rolls, k), 3);
}

TEST_P(ShortestImpossibleSequenceOfRollsTest, Example2) {
  std::vector<int> rolls = {1, 1, 2, 2};
  int k = 2;
  EXPECT_EQ(solution.shortestSequence(rolls, k), 2);
}

TEST_P(ShortestImpossibleSequenceOfRollsTest, Example3) {
  std::vector<int> rolls = {1, 1, 3, 2, 2, 2, 3, 3};
  int k = 4;
  EXPECT_EQ(solution.shortestSequence(rolls, k), 1);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies, ShortestImpossibleSequenceOfRollsTest,
    testing::ValuesIn(
        ShortestImpossibleSequenceOfRollsSolution().getStrategyNames()));

}  // namespace problem_2350
}  // namespace leetcode
