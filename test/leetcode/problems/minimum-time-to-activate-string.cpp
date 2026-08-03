#include <gtest/gtest.h>

#include "leetcode/problems/minimum-time-to-activate-string.h"

namespace leetcode::problem_3639 {

class MinimumTimeToActivateStringTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  MinimumTimeToActivateStringSolution solution;

  void SetUp() override { solution.setStrategy(GetParam()); }
};

TEST_P(MinimumTimeToActivateStringTest, Example1) {
  std::string s = "abc";
  std::vector<int> order = {1, 0, 2};
  int k = 2;
  EXPECT_EQ(solution.minTime(s, order, k), 0);
}

TEST_P(MinimumTimeToActivateStringTest, Example2) {
  std::string s = "cat";
  std::vector<int> order = {0, 2, 1};
  int k = 6;
  EXPECT_EQ(solution.minTime(s, order, k), 2);
}

TEST_P(MinimumTimeToActivateStringTest, Example3) {
  std::string s = "xy";
  std::vector<int> order = {0, 1};
  int k = 4;
  EXPECT_EQ(solution.minTime(s, order, k), -1);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies, MinimumTimeToActivateStringTest,
    ::testing::ValuesIn(
        MinimumTimeToActivateStringSolution().getStrategyNames()));

}  // namespace leetcode::problem_3639
