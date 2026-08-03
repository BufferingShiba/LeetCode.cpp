
#include "leetcode/problems/apply-operations-to-make-string-empty.h"

#include "gtest/gtest.h"

namespace leetcode {
namespace problem_3039 {

class ApplyOperationsToMakeStringEmptyTest : public ::testing::TestWithParam<string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  ApplyOperationsToMakeStringEmptySolution solution;
};

TEST_P(ApplyOperationsToMakeStringEmptyTest, Example1) {
  std::string s = "aabcbbca";
  std::string expected = "ba";
  EXPECT_EQ(expected, solution.lastNonEmptyString(s));
}

TEST_P(ApplyOperationsToMakeStringEmptyTest, Example2) {
  std::string s = "abcd";
  std::string expected = "abcd";
  EXPECT_EQ(expected, solution.lastNonEmptyString(s));
}

TEST_P(ApplyOperationsToMakeStringEmptyTest, SelfAuthoredSingleChar) {
  std::string s = "a";
  std::string expected = "a";
  EXPECT_EQ(expected, solution.lastNonEmptyString(s));
}

TEST_P(ApplyOperationsToMakeStringEmptyTest, SelfAuthoredAllSameChar) {
  std::string s = "zzzz";
  std::string expected = "z";
  EXPECT_EQ(expected, solution.lastNonEmptyString(s));
}

TEST_P(ApplyOperationsToMakeStringEmptyTest, SelfAuthoredMixedFrequencies) {
  // a 出现 3 次、b 出现 2 次、c 出现 1 次。maxFreq=3，只有 a 保留（最后一次出现的 a）。
  std::string s = "ababca";
  std::string expected = "a";
  EXPECT_EQ(expected, solution.lastNonEmptyString(s));
}

INSTANTIATE_TEST_SUITE_P(
    LeetCode, ApplyOperationsToMakeStringEmptyTest,
    ::testing::ValuesIn(ApplyOperationsToMakeStringEmptySolution().getStrategyNames()));

}  // namespace problem_3039
}  // namespace leetcode
