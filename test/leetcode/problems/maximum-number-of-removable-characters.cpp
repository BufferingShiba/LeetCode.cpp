#include <string>
#include <vector>

#include <gtest/gtest.h>

#include "leetcode/problems/maximum-number-of-removable-characters.h"

namespace leetcode {
namespace problem_1898 {
namespace {

using MaximumNumberOfRemovableCharactersTest = ::testing::TestWithParam<std::string>;

}  // namespace

TEST_P(MaximumNumberOfRemovableCharactersTest, Example1) {
  MaximumNumberOfRemovableCharactersSolution solution;
  solution.setStrategy(GetParam());
  std::string s = "abcacb";
  std::string p = "ab";
  std::vector<int> removable = {3, 1, 0};
  EXPECT_EQ(2, solution.maximumRemovals(s, p, removable));
}

TEST_P(MaximumNumberOfRemovableCharactersTest, Example2) {
  MaximumNumberOfRemovableCharactersSolution solution;
  solution.setStrategy(GetParam());
  std::string s = "abcbddddd";
  std::string p = "abcd";
  std::vector<int> removable = {3, 2, 1, 4, 5, 6};
  EXPECT_EQ(1, solution.maximumRemovals(s, p, removable));
}

TEST_P(MaximumNumberOfRemovableCharactersTest, Example3) {
  MaximumNumberOfRemovableCharactersSolution solution;
  solution.setStrategy(GetParam());
  std::string s = "abcab";
  std::string p = "abc";
  std::vector<int> removable = {0, 1, 2, 3, 4};
  EXPECT_EQ(0, solution.maximumRemovals(s, p, removable));
}

TEST_P(MaximumNumberOfRemovableCharactersTest, SelfAuthoredZeroRemovable) {
  MaximumNumberOfRemovableCharactersSolution solution;
  solution.setStrategy(GetParam());
  std::string s = "abc";
  std::string p = "abc";
  std::vector<int> removable = {};
  EXPECT_EQ(0, solution.maximumRemovals(s, p, removable));
}

TEST_P(MaximumNumberOfRemovableCharactersTest, SelfAuthoredRemovableAllButP) {
  MaximumNumberOfRemovableCharactersSolution solution;
  solution.setStrategy(GetParam());
  // Remove up to indices 1 and 3 (chars 'b' and 'd'); p="ac" still survives.
  std::string s = "a b c d";
  s = "abcd";
  std::string p = "ac";
  std::vector<int> removable = {1, 3};
  EXPECT_EQ(2, solution.maximumRemovals(s, p, removable));
}

INSTANTIATE_TEST_SUITE_P(
    MaximumNumberOfRemovableCharactersTestInstance,
    MaximumNumberOfRemovableCharactersTest,
    ::testing::ValuesIn(MaximumNumberOfRemovableCharactersSolution().getStrategyNames()));

}  // namespace problem_1898
}  // namespace leetcode
