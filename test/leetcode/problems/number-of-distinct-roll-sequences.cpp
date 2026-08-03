#include <gtest/gtest.h>

#include "leetcode/problems/number-of-distinct-roll-sequences.h"

namespace leetcode::problem_2318 {

class NumberOfDistinctRollSequencesTest : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }
  NumberOfDistinctRollSequencesSolution solution_;
};

TEST_P(NumberOfDistinctRollSequencesTest, Example1) {
  EXPECT_EQ(solution_.distinctSequences(4), 184);
}

TEST_P(NumberOfDistinctRollSequencesTest, Example2) {
  EXPECT_EQ(solution_.distinctSequences(2), 22);
}

TEST_P(NumberOfDistinctRollSequencesTest, SelfAuthoredN1) {
  EXPECT_EQ(solution_.distinctSequences(1), 6);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    NumberOfDistinctRollSequencesTest,
    testing::ValuesIn(NumberOfDistinctRollSequencesSolution().getStrategyNames()));

}  // namespace leetcode::problem_2318
