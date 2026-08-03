#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/valid-permutations-for-di-sequence.h"

namespace leetcode {
namespace problem_903 {

class ValidPermutationsForDiSequenceTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  ValidPermutationsForDiSequenceSolution solution_;
};

TEST_P(ValidPermutationsForDiSequenceTest, Example1) {
  EXPECT_EQ(solution_.numPermsDISequence("DID"), 5);
}

TEST_P(ValidPermutationsForDiSequenceTest, Example2) {
  EXPECT_EQ(solution_.numPermsDISequence("D"), 1);
}

TEST_P(ValidPermutationsForDiSequenceTest, SelfAuthoredSingleIncreasing) {
  EXPECT_EQ(solution_.numPermsDISequence("I"), 1);
}

TEST_P(ValidPermutationsForDiSequenceTest, SelfAuthoredAllIncreasing) {
  // s = "II": only (0,1,2) satisfies both increases.
  EXPECT_EQ(solution_.numPermsDISequence("II"), 1);
}

TEST_P(ValidPermutationsForDiSequenceTest, SelfAuthoredAllDecreasing) {
  // s = "DD": only (2,1,0) satisfies both decreases.
  EXPECT_EQ(solution_.numPermsDISequence("DD"), 1);
}

TEST_P(ValidPermutationsForDiSequenceTest, SelfAuthoredLengthTwo) {
  // s = "DI": valid perms of (0,1,2): pass -> (2,0,1), (1,0,2).
  EXPECT_EQ(solution_.numPermsDISequence("DI"), 2);
}

INSTANTIATE_TEST_SUITE_P(
    ValidPermutationsForDiSequenceTestSuite,
    ValidPermutationsForDiSequenceTest,
    ::testing::ValuesIn(
        ValidPermutationsForDiSequenceSolution().getStrategyNames()));

}  // namespace problem_903
}  // namespace leetcode
