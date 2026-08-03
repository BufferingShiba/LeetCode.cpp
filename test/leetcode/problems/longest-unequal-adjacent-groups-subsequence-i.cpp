#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/longest-unequal-adjacent-groups-subsequence-i.h"

namespace leetcode {
namespace problem_2900 {

class LongestUnequalAdjacentGroupsSubsequenceITest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  LongestUnequalAdjacentGroupsSubsequenceISolution solution;
};

TEST_P(LongestUnequalAdjacentGroupsSubsequenceITest, Example1) {
  std::vector<std::string> words = {"e", "a", "b"};
  std::vector<int> groups = {0, 0, 1};
  std::vector<std::string> result =
      solution.getLongestSubsequence(words, groups);
  std::vector<std::string> expected = {"e", "b"};
  EXPECT_EQ(result, expected);
}

TEST_P(LongestUnequalAdjacentGroupsSubsequenceITest, Example2) {
  std::vector<std::string> words = {"a", "b", "c", "d"};
  std::vector<int> groups = {1, 0, 1, 1};
  std::vector<std::string> result =
      solution.getLongestSubsequence(words, groups);
  std::vector<std::string> expected = {"a", "b", "c"};
  EXPECT_EQ(result, expected);
}

TEST_P(LongestUnequalAdjacentGroupsSubsequenceITest, SelfAuthoredSingleElement) {
  std::vector<std::string> words = {"hello"};
  std::vector<int> groups = {1};
  std::vector<std::string> result =
      solution.getLongestSubsequence(words, groups);
  std::vector<std::string> expected = {"hello"};
  EXPECT_EQ(result, expected);
}

TEST_P(LongestUnequalAdjacentGroupsSubsequenceITest,
       ComparesAgainstLastSelectedGroup) {
  std::vector<std::string> words = {"r", "k", "pb", "x"};
  std::vector<int> groups = {0, 0, 1, 0};
  std::vector<std::string> result =
      solution.getLongestSubsequence(words, groups);
  std::vector<std::string> expected = {"r", "pb", "x"};
  EXPECT_EQ(result, expected);
}

INSTANTIATE_TEST_SUITE_P(
    LongestUnequalAdjacentGroupsSubsequenceITests,
    LongestUnequalAdjacentGroupsSubsequenceITest,
    ::testing::ValuesIn(
        LongestUnequalAdjacentGroupsSubsequenceISolution()
            .getStrategyNames()));

}  // namespace problem_2900
}  // namespace leetcode
