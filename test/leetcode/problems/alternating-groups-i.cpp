#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/alternating-groups-i.h"

namespace leetcode {
namespace problem_3206 {
namespace {

class AlternatingGroupsITest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  AlternatingGroupsISolution solution;
};

TEST_P(AlternatingGroupsITest, Example1) {
  std::vector<int> colors = {1, 1, 1};
  EXPECT_EQ(0, solution.numberOfAlternatingGroups(colors));
}

TEST_P(AlternatingGroupsITest, Example2) {
  std::vector<int> colors = {0, 1, 0, 0, 1};
  EXPECT_EQ(3, solution.numberOfAlternatingGroups(colors));
}

TEST_P(AlternatingGroupsITest, LengthThreeAlternating) {
  std::vector<int> colors = {0, 1, 0};
  EXPECT_EQ(1, solution.numberOfAlternatingGroups(colors));
}

TEST_P(AlternatingGroupsITest, LengthThreeWithWrap) {
  std::vector<int> colors = {0, 1, 1};
  EXPECT_EQ(1, solution.numberOfAlternatingGroups(colors));
}

INSTANTIATE_TEST_SUITE_P(
    AlternatingGroupsITestSuite, AlternatingGroupsITest,
    ::testing::ValuesIn(AlternatingGroupsISolution().getStrategyNames()));

}  // namespace
}  // namespace problem_3206
}  // namespace leetcode
