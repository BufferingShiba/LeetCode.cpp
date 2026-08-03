#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/groups-of-strings.h"

namespace leetcode::problem_2157 {

class GroupsOfStringsTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }
  GroupsOfStringsSolution solution;
};

TEST_P(GroupsOfStringsTest, Example1) {
  std::vector<std::string> words = {"a", "b", "ab", "cde"};
  EXPECT_EQ((std::vector<int>{2, 3}), solution.groupStrings(words));
}

TEST_P(GroupsOfStringsTest, Example2) {
  std::vector<std::string> words = {"a", "ab", "abc"};
  EXPECT_EQ((std::vector<int>{1, 3}), solution.groupStrings(words));
}

TEST_P(GroupsOfStringsTest, SelfAuthoredSingleWord) {
  std::vector<std::string> words = {"z"};
  EXPECT_EQ((std::vector<int>{1, 1}), solution.groupStrings(words));
}

TEST_P(GroupsOfStringsTest, SelfAuthoredDuplicateMasks) {
  std::vector<std::string> words = {"ab", "ba", "c"};
  EXPECT_EQ((std::vector<int>{2, 2}), solution.groupStrings(words));
}

INSTANTIATE_TEST_SUITE_P(
    GroupsOfStringsTests, GroupsOfStringsTest,
    ::testing::ValuesIn(GroupsOfStringsSolution().getStrategyNames()));

}  // namespace leetcode::problem_2157
