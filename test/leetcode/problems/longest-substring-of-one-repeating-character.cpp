#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/longest-substring-of-one-repeating-character.h"

namespace leetcode {
namespace problem_2213 {

class LongestSubstringOfOneRepeatingCharacterTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  LongestSubstringOfOneRepeatingCharacterSolution solution;

  void SetUp() override { solution.setStrategy(GetParam()); }
};

TEST_P(LongestSubstringOfOneRepeatingCharacterTest, Example1) {
  std::string s = "babacc";
  std::string queryCharacters = "bcb";
  std::vector<int> queryIndices = {1, 3, 3};
  std::vector<int> expected = {3, 3, 4};
  EXPECT_EQ(solution.longestRepeating(s, queryCharacters, queryIndices), expected);
}

TEST_P(LongestSubstringOfOneRepeatingCharacterTest, Example2) {
  std::string s = "abyzz";
  std::string queryCharacters = "aa";
  std::vector<int> queryIndices = {2, 1};
  std::vector<int> expected = {2, 3};
  EXPECT_EQ(solution.longestRepeating(s, queryCharacters, queryIndices), expected);
}

INSTANTIATE_TEST_SUITE_P(
    LongestSubstringOfOneRepeatingCharacterTestParams,
    LongestSubstringOfOneRepeatingCharacterTest,
    ::testing::ValuesIn(LongestSubstringOfOneRepeatingCharacterSolution().getStrategyNames()));

}  // namespace problem_2213
}  // namespace leetcode
