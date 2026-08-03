#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/count-the-number-of-winning-sequences.h"

namespace leetcode::problem_3320 {

class CountTheNumberOfWinningSequencesTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  CountTheNumberOfWinningSequencesSolution solution_;
};

TEST_P(CountTheNumberOfWinningSequencesTest, Example1) {
  EXPECT_EQ(3, solution_.countWinningSequences("FFF"));
}

TEST_P(CountTheNumberOfWinningSequencesTest, Example2) {
  EXPECT_EQ(18, solution_.countWinningSequences("FWEFW"));
}

TEST_P(CountTheNumberOfWinningSequencesTest, SelfAuthoredSingleRound) {
  // n = 1: Bob has only 1 valid move that beats Alice's move.
  EXPECT_EQ(1, solution_.countWinningSequences("F"));
  EXPECT_EQ(1, solution_.countWinningSequences("W"));
  EXPECT_EQ(1, solution_.countWinningSequences("E"));
}

INSTANTIATE_TEST_SUITE_P(
    CountTheNumberOfWinningSequencesParam,
    CountTheNumberOfWinningSequencesTest,
    ::testing::ValuesIn(CountTheNumberOfWinningSequencesSolution().getStrategyNames()));

}  // namespace leetcode::problem_3320
