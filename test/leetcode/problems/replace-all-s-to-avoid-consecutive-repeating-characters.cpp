#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/replace-all-s-to-avoid-consecutive-repeating-characters.h"

namespace leetcode {
namespace problem_1576 {

namespace {

bool isValid(const std::string& s) {
  for (size_t i = 1; i < s.size(); ++i) {
    if (s[i] == s[i - 1]) return false;
  }
  return true;
}

}  // namespace

class ReplaceAllSToAvoidConsecutiveRepeatingCharactersTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  ReplaceAllSToAvoidConsecutiveRepeatingCharactersSolution solution_;
};

TEST_P(ReplaceAllSToAvoidConsecutiveRepeatingCharactersTest, Example1) {
  std::string result = solution_.modifyString("?zs");
  EXPECT_EQ(result.size(), 3u);
  EXPECT_TRUE(isValid(result));
}

TEST_P(ReplaceAllSToAvoidConsecutiveRepeatingCharactersTest, Example2) {
  std::string result = solution_.modifyString("ubv?w");
  EXPECT_EQ(result.size(), 5u);
  EXPECT_TRUE(isValid(result));
}

TEST_P(ReplaceAllSToAvoidConsecutiveRepeatingCharactersTest, SelfAuthoredAllQuestionMarks) {
  std::string result = solution_.modifyString("???");
  EXPECT_EQ(result.size(), 3u);
  EXPECT_TRUE(isValid(result));
}

TEST_P(ReplaceAllSToAvoidConsecutiveRepeatingCharactersTest, SelfAuthoredMixedEdge) {
  std::string result = solution_.modifyString("a?b?a");
  EXPECT_EQ(result.size(), 5u);
  EXPECT_TRUE(isValid(result));
}

INSTANTIATE_TEST_SUITE_P(
    ReplaceAllSToAvoidConsecutiveRepeatingCharactersTestCases,
    ReplaceAllSToAvoidConsecutiveRepeatingCharactersTest,
    ::testing::ValuesIn(
        ReplaceAllSToAvoidConsecutiveRepeatingCharactersSolution()
            .getStrategyNames()));

}  // namespace problem_1576
}  // namespace leetcode
