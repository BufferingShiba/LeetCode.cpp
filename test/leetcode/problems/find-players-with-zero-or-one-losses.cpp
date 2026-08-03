#include <gtest/gtest.h>

#include <vector>

#include "leetcode/problems/find-players-with-zero-or-one-losses.h"

namespace leetcode {
namespace problem_2225 {
namespace {

using ::testing::TestWithParam;
using ::testing::ValuesIn;

class FindPlayersWithZeroOrOneLossesTest : public TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  FindPlayersWithZeroOrOneLossesSolution solution_;
};

TEST_P(FindPlayersWithZeroOrOneLossesTest, Example1) {
  std::vector<std::vector<int>> matches = {
      {1, 3}, {2, 3}, {3, 6}, {5, 6}, {5, 7},
      {4, 5}, {4, 8}, {4, 9}, {10, 4}, {10, 9}};
  std::vector<std::vector<int>> expected = {{1, 2, 10}, {4, 5, 7, 8}};
  EXPECT_EQ(solution_.findWinners(matches), expected);
}

TEST_P(FindPlayersWithZeroOrOneLossesTest, Example2) {
  std::vector<std::vector<int>> matches = {{2, 3}, {1, 3}, {5, 4}, {6, 4}};
  std::vector<std::vector<int>> expected = {{1, 2, 5, 6}, {}};
  EXPECT_EQ(solution_.findWinners(matches), expected);
}

TEST_P(FindPlayersWithZeroOrOneLossesTest, SelfAuthoredSingleMatch) {
  std::vector<std::vector<int>> matches = {{1, 2}};
  std::vector<std::vector<int>> expected = {{1}, {2}};
  EXPECT_EQ(solution_.findWinners(matches), expected);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    FindPlayersWithZeroOrOneLossesTest,
    ValuesIn(FindPlayersWithZeroOrOneLossesSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_2225
}  // namespace leetcode
