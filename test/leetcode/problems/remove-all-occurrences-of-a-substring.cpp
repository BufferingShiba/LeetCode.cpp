#include <gtest/gtest.h>

#include "leetcode/problems/remove-all-occurrences-of-a-substring.h"

namespace leetcode {
namespace problem_1910 {

class RemoveAllOccurrencesOfASubstringTest
    : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  RemoveAllOccurrencesOfASubstringSolution solution;
};

TEST_P(RemoveAllOccurrencesOfASubstringTest, Example1) {
  EXPECT_EQ(solution.removeOccurrences("daabcbaabcbc", "abc"), "dab");
}

TEST_P(RemoveAllOccurrencesOfASubstringTest, Example2) {
  EXPECT_EQ(solution.removeOccurrences("axxxxyyyyb", "xy"), "ab");
}

TEST_P(RemoveAllOccurrencesOfASubstringTest, SelfAuthoredNoMatch) {
  EXPECT_EQ(solution.removeOccurrences("abcdef", "xyz"), "abcdef");
}

TEST_P(RemoveAllOccurrencesOfASubstringTest, SelfAuthoredSingleRemoval) {
  EXPECT_EQ(solution.removeOccurrences("hello", "ll"), "heo");
}

TEST_P(RemoveAllOccurrencesOfASubstringTest, SelfAuthoredCascadingRemoval) {
  // Removing "ab" from "aabb" → first remove "ab" at index 1 → "aab" → remove "ab" → "a"
  EXPECT_EQ(solution.removeOccurrences("aabb", "ab"), "");
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    RemoveAllOccurrencesOfASubstringTest,
    testing::ValuesIn(
        RemoveAllOccurrencesOfASubstringSolution().getStrategyNames()));

}  // namespace problem_1910
}  // namespace leetcode
