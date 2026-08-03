#include "leetcode/problems/find-mirror-score-of-a-string.h"

#include "gtest/gtest.h"

namespace leetcode {
namespace problem_3412 {

class FindMirrorScoreOfAStringTest : public ::testing::TestWithParam<string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  FindMirrorScoreOfAStringSolution solution;
};

// ===== Official Example 1 (from LeetCode) =====
// Input:  s = "aczzx"
// Output: 5
TEST_P(FindMirrorScoreOfAStringTest, OfficialExample1) {
  EXPECT_EQ(5L, solution.calculateScore("aczzx"));
}

// ===== Official Example 2 (from LeetCode) =====
// Input:  s = "abcdef"
// Output: 0
TEST_P(FindMirrorScoreOfAStringTest, OfficialExample2) {
  EXPECT_EQ(0L, solution.calculateScore("abcdef"));
}

// ===== Self-authored: adjacent non-mirror letters never match =====
// "ab": mirror of 'b' is 'y' (not 'a'), mirror of 'a' is 'z'. No pair -> 0.
TEST_P(FindMirrorScoreOfAStringTest, AdjacentNonMirror) {
  EXPECT_EQ(0L, solution.calculateScore("ab"));
}

// ===== Self-authored: "az" mirror pair =====
// mirror of 'z' is 'a'; processing index 0 ('a') pushes 0;
// index 1 ('z') finds mirror 'a' at 0 -> score += 1.
TEST_P(FindMirrorScoreOfAStringTest, MirroredPair) {
  EXPECT_EQ(1L, solution.calculateScore("az"));
}

// ===== Self-authored: "za" mirror pair =====
// mirror of 'a' is 'z'; index 0 ('z') pushed, index 1 ('a') matches -> +1.
TEST_P(FindMirrorScoreOfAStringTest, ReverseMirroredPair) {
  EXPECT_EQ(1L, solution.calculateScore("za"));
}

// ===== Self-authored: identical letters never match (mirror of
// a letter is never itself) =====
TEST_P(FindMirrorScoreOfAStringTest, IdenticalNeverMatch) {
  EXPECT_EQ(0L, solution.calculateScore("aaa"));
}

INSTANTIATE_TEST_SUITE_P(
    LeetCode, FindMirrorScoreOfAStringTest,
    ::testing::ValuesIn(FindMirrorScoreOfAStringSolution().getStrategyNames()));

}  // namespace problem_3412
}  // namespace leetcode
