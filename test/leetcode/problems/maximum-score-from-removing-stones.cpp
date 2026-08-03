#include "leetcode/problems/maximum-score-from-removing-stones.h"

#include <gtest/gtest.h>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_1753 {
namespace {

class MaximumScoreFromRemovingStonesTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  MaximumScoreFromRemovingStonesSolution solution;
};

TEST_P(MaximumScoreFromRemovingStonesTest, Example1) {
  EXPECT_EQ(solution.maximumScore(2, 4, 6), 6);
}

TEST_P(MaximumScoreFromRemovingStonesTest, Example2) {
  EXPECT_EQ(solution.maximumScore(4, 4, 6), 7);
}

TEST_P(MaximumScoreFromRemovingStonesTest, Example3) {
  EXPECT_EQ(solution.maximumScore(1, 8, 8), 8);
}

TEST_P(MaximumScoreFromRemovingStonesTest, SelfAuthoredLargestDominates) {
  // z >= x + y => answer = x + y
  EXPECT_EQ(solution.maximumScore(1, 1, 100), 2);
}

TEST_P(MaximumScoreFromRemovingStonesTest, SelfAuthoredEqualPiles) {
  EXPECT_EQ(solution.maximumScore(1, 1, 1), 1);
}

TEST_P(MaximumScoreFromRemovingStonesTest, SelfAuthoredAllEqualLarge) {
  EXPECT_EQ(solution.maximumScore(5, 5, 5), 7);  // 15/2 = 7
}

INSTANTIATE_TEST_SUITE_P(
    MaximumScoreFromRemovingStonesTestSuite, MaximumScoreFromRemovingStonesTest,
    ::testing::ValuesIn(MaximumScoreFromRemovingStonesSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_1753
}  // namespace leetcode
