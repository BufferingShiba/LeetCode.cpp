#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/find-the-lexicographically-smallest-valid-sequence.h"

namespace leetcode::problem_3302 {

class FindTheLexicographicallySmallestValidSequenceTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

 public:
  FindTheLexicographicallySmallestValidSequenceSolution solution_;
};

TEST_P(FindTheLexicographicallySmallestValidSequenceTest, Example1) {
  EXPECT_EQ(solution_.validSequence("vbcca", "abc"),
            (std::vector<int>{0, 1, 2}));
}

TEST_P(FindTheLexicographicallySmallestValidSequenceTest, Example2) {
  EXPECT_EQ(solution_.validSequence("bacdc", "abc"),
            (std::vector<int>{1, 2, 4}));
}

TEST_P(FindTheLexicographicallySmallestValidSequenceTest, Example3) {
  EXPECT_EQ(solution_.validSequence("aaaaaa", "aaabc"),
            (std::vector<int>{}));
}

TEST_P(FindTheLexicographicallySmallestValidSequenceTest, Example4) {
  EXPECT_EQ(solution_.validSequence("abc", "ab"), (std::vector<int>{0, 1}));
}

TEST_P(FindTheLexicographicallySmallestValidSequenceTest, SelfAuthoredChangeLastChar) {
  EXPECT_EQ(solution_.validSequence("ac", "ab"), (std::vector<int>{0, 1}));
}

TEST_P(FindTheLexicographicallySmallestValidSequenceTest, SelfAuthoredChangeFirstChar) {
  // word1="kcbd", word2="acbd"; change word1[0]='k'->'a'. strictly matches rest.
  EXPECT_EQ(solution_.validSequence("kbcd", "abcd"),
            (std::vector<int>{0, 1, 2, 3}));
}

INSTANTIATE_TEST_SUITE_P(
    FindTheLexicographicallySmallestValidSequenceTestSuite,
    FindTheLexicographicallySmallestValidSequenceTest,
    ::testing::ValuesIn(
        FindTheLexicographicallySmallestValidSequenceSolution()
            .getStrategyNames()));

}  // namespace leetcode::problem_3302
