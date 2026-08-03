#include <gtest/gtest.h>

#include <string>

#include "leetcode/problems/longest-duplicate-substring.h"

namespace leetcode {
namespace problem_1044 {
namespace {

class LongestDuplicateSubstringTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  LongestDuplicateSubstringSolution solution;
};

TEST_P(LongestDuplicateSubstringTest, Example1_Banana) {
  std::string s = "banana";
  auto result = solution.longestDupSubstring(s);
  // The longest duplicate is "ana" (length 3)
  EXPECT_EQ(result.size(), 3u);
}

TEST_P(LongestDuplicateSubstringTest, Example2_Abcd) {
  std::string s = "abcd";
  auto result = solution.longestDupSubstring(s);
  EXPECT_EQ(result, "");
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    LongestDuplicateSubstringTest,
    ::testing::ValuesIn(
        LongestDuplicateSubstringSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_1044
}  // namespace leetcode
