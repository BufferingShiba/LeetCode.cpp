#include <gtest/gtest.h>
#include <string>
#include <vector>

#include "leetcode/problems/minimum-deletions-to-make-character-frequencies-unique.h"

namespace leetcode {
namespace problem_1647 {

class MinimumDeletionsToMakeCharacterFrequenciesUniqueTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  MinimumDeletionsToMakeCharacterFrequenciesUniqueSolution solution_;
};

TEST_P(MinimumDeletionsToMakeCharacterFrequenciesUniqueTest, Example1) {
  EXPECT_EQ(solution_.minDeletions("aab"), 0);
}

TEST_P(MinimumDeletionsToMakeCharacterFrequenciesUniqueTest, Example2) {
  EXPECT_EQ(solution_.minDeletions("aaabbbcc"), 2);
}

TEST_P(MinimumDeletionsToMakeCharacterFrequenciesUniqueTest, Example3) {
  EXPECT_EQ(solution_.minDeletions("ceabaacb"), 2);
}

TEST_P(MinimumDeletionsToMakeCharacterFrequenciesUniqueTest, SelfAuthoredAllSame) {
  EXPECT_EQ(solution_.minDeletions("aaaa"), 0);
}

TEST_P(MinimumDeletionsToMakeCharacterFrequenciesUniqueTest, SelfAuthoredThreeSameFreq) {
  // aabbcc: freqs {2,2,2} -> need to delete to {2,1,0} = 3 deletions
  EXPECT_EQ(solution_.minDeletions("aabbcc"), 3);
}

TEST_P(MinimumDeletionsToMakeCharacterFrequenciesUniqueTest, SelfAuthoredSingleChar) {
  EXPECT_EQ(solution_.minDeletions("a"), 0);
}


// LeetCode 失败用例: WrongAnswerCase1
TEST_P(MinimumDeletionsToMakeCharacterFrequenciesUniqueTest, WrongAnswerCase1) {
  // 输入: s = "bbcebab", freqs {3,1,1,1} -> expected 2
    EXPECT_EQ(solution_.minDeletions("bbcebab"), 2);
}
INSTANTIATE_TEST_SUITE_P(
    MinimumDeletionsToMakeCharacterFrequenciesUniqueTestCases,
    MinimumDeletionsToMakeCharacterFrequenciesUniqueTest,
    ::testing::ValuesIn(
        MinimumDeletionsToMakeCharacterFrequenciesUniqueSolution()
            .getStrategyNames()));

}  // namespace problem_1647
}  // namespace leetcode
