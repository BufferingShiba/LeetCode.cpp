#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/groups-of-special-equivalent-strings.h"

namespace leetcode {
namespace problem_893 {

class GroupsOfSpecialEquivalentStringsTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  GroupsOfSpecialEquivalentStringsSolution solution;
};

TEST_P(GroupsOfSpecialEquivalentStringsTest, Example1) {
  std::vector<std::string> words = {"abcd", "cdab", "cbad", "xyzz", "zzxy", "zzyx"};
  EXPECT_EQ(3, solution.numSpecialEquivGroups(words));
}

TEST_P(GroupsOfSpecialEquivalentStringsTest, Example2) {
  std::vector<std::string> words = {"abc", "acb", "bac", "bca", "cab", "cba"};
  EXPECT_EQ(3, solution.numSpecialEquivGroups(words));
}

TEST_P(GroupsOfSpecialEquivalentStringsTest, SelfAuthoredSingleWord) {
  std::vector<std::string> words = {"ab"};
  EXPECT_EQ(1, solution.numSpecialEquivGroups(words));
}

TEST_P(GroupsOfSpecialEquivalentStringsTest, SelfAuthoredAllEqualSingleGroup) {
  std::vector<std::string> words = {"aa", "aa", "aa"};
  EXPECT_EQ(1, solution.numSpecialEquivGroups(words));
}

TEST_P(GroupsOfSpecialEquivalentStringsTest, SelfAuthoredDistinctGroups) {
  std::vector<std::string> words = {"a", "b", "c"};
  EXPECT_EQ(3, solution.numSpecialEquivGroups(words));
}

INSTANTIATE_TEST_SUITE_P(
    GroupsOfSpecialEquivalentStringsTestSuite,
    GroupsOfSpecialEquivalentStringsTest,
    testing::ValuesIn(GroupsOfSpecialEquivalentStringsSolution().getStrategyNames()));

}  // namespace problem_893
}  // namespace leetcode
