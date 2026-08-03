#include <gtest/gtest.h>

#include "leetcode/problems/last-stone-weight-ii.h"

#include <string>
#include <vector>

namespace leetcode {
namespace problem_1049 {
namespace {

using LastStoneWeightIiTest = testing::TestWithParam<std::string>;

class LastStoneWeightIiFixture : public LastStoneWeightIiTest {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  LastStoneWeightIiSolution solution;
};

TEST_P(LastStoneWeightIiFixture, Example1) {
  std::vector<int> stones = {2, 7, 4, 1, 8, 1};
  EXPECT_EQ(solution.lastStoneWeightII(stones), 1);
}

TEST_P(LastStoneWeightIiFixture, Example2) {
  std::vector<int> stones = {31, 26, 33, 21, 40};
  EXPECT_EQ(solution.lastStoneWeightII(stones), 5);
}

TEST_P(LastStoneWeightIiFixture, SelfAuthoredSingleStone) {
  std::vector<int> stones = {5};
  EXPECT_EQ(solution.lastStoneWeightII(stones), 5);
}

TEST_P(LastStoneWeightIiFixture, SelfAuthoredTwoEqualStones) {
  std::vector<int> stones = {3, 3};
  EXPECT_EQ(solution.lastStoneWeightII(stones), 0);
}

TEST_P(LastStoneWeightIiFixture, SelfAuthoredEqualSplit) {
  std::vector<int> stones = {1, 2, 3};
  // 6 -> best subset sum <= 3 is 3 -> 6 - 6 = 0
  EXPECT_EQ(solution.lastStoneWeightII(stones), 0);
}

INSTANTIATE_TEST_SUITE_P(
    LastStoneWeightIiSuite,
    LastStoneWeightIiFixture,
    testing::ValuesIn(LastStoneWeightIiSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_1049
}  // namespace leetcode
