#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/subsequence-with-the-minimum-score.h"

namespace leetcode {
namespace problem_2565 {

class SubsequenceWithTheMinimumScoreTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  SubsequenceWithTheMinimumScoreSolution solution_;
};

TEST_P(SubsequenceWithTheMinimumScoreTest, Example1) {
  EXPECT_EQ(solution_.minimumScore("abacaba", "bzaa"), 1);
}

TEST_P(SubsequenceWithTheMinimumScoreTest, Example2) {
  EXPECT_EQ(solution_.minimumScore("cde", "xyz"), 3);
}

TEST_P(SubsequenceWithTheMinimumScoreTest, SelfAuthoredAlreadySubsequence) {
  EXPECT_EQ(solution_.minimumScore("abacaba", "abc"), 0);
}

TEST_P(SubsequenceWithTheMinimumScoreTest, SelfAuthoredRemoveAll) {
  // t shares no proper subsequence match beyond empty; must remove everything.
  EXPECT_EQ(solution_.minimumScore("aaa", "bbb"), 3);
}

TEST_P(SubsequenceWithTheMinimumScoreTest, SelfAuthoredRemoveMiddleWindow) {
  // t = "abcXdef", s = "abcdef". Keep "abcdef" by removing 'X'.
  EXPECT_EQ(solution_.minimumScore("abcdef", "abcXdef"), 1);
}

TEST_P(SubsequenceWithTheMinimumScoreTest, SelfAuthoredSingleMatchingEdge) {
  // s = "a", t = "ba": keep 'a' (from t index 1), remove 'b' => score 1.
  EXPECT_EQ(solution_.minimumScore("a", "ba"), 1);
}

INSTANTIATE_TEST_SUITE_P(
    SubsequenceWithTheMinimumScoreTestSuite,
    SubsequenceWithTheMinimumScoreTest,
    ::testing::ValuesIn(
        SubsequenceWithTheMinimumScoreSolution().getStrategyNames()));

}  // namespace problem_2565
}  // namespace leetcode
