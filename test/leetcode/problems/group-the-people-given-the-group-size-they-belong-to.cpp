#include <gtest/gtest.h>

#include <algorithm>
#include <string>
#include <vector>

#include "leetcode/problems/group-the-people-given-the-group-size-they-belong-to.h"

namespace leetcode {
namespace problem_1282 {
namespace {

bool isValid(const std::vector<std::vector<int>>& result,
             const std::vector<int>& groupSizes) {
  std::vector<bool> used(groupSizes.size(), false);
  for (const auto& group : result) {
    if (group.empty()) return false;
    int expected = groupSizes[group[0]];
    if (static_cast<int>(group.size()) != expected) return false;
    for (int idx : group) {
      if (idx < 0 || idx >= static_cast<int>(groupSizes.size())) return false;
      if (used[idx]) return false;
      if (groupSizes[idx] != expected) return false;
      used[idx] = true;
    }
  }
  return std::all_of(used.begin(), used.end(), [](bool v) { return v; });
}

}  // namespace

class GroupThePeopleGivenTheGroupSizeTheyBelongToTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  GroupThePeopleGivenTheGroupSizeTheyBelongToSolution solution_;
};

TEST_P(GroupThePeopleGivenTheGroupSizeTheyBelongToTest, Example1) {
  std::vector<int> groupSizes = {3, 3, 3, 3, 3, 1, 3};
  auto result = solution_.groupThePeople(groupSizes);
  EXPECT_TRUE(isValid(result, groupSizes));
}

TEST_P(GroupThePeopleGivenTheGroupSizeTheyBelongToTest, Example2) {
  std::vector<int> groupSizes = {2, 1, 3, 3, 3, 2};
  auto result = solution_.groupThePeople(groupSizes);
  EXPECT_TRUE(isValid(result, groupSizes));
}

TEST_P(GroupThePeopleGivenTheGroupSizeTheyBelongToTest, SelfAuthoredAllSameSize) {
  std::vector<int> groupSizes = {2, 2, 2, 2};
  auto result = solution_.groupThePeople(groupSizes);
  EXPECT_TRUE(isValid(result, groupSizes));
}

INSTANTIATE_TEST_SUITE_P(
    GroupThePeopleGivenTheGroupSizeTheyBelongToTestCases,
    GroupThePeopleGivenTheGroupSizeTheyBelongToTest,
    ::testing::ValuesIn(
        GroupThePeopleGivenTheGroupSizeTheyBelongToSolution().getStrategyNames()));

}  // namespace problem_1282
}  // namespace leetcode
