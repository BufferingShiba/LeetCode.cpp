#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/most-stones-removed-with-same-row-or-column.h"

namespace leetcode::problem_947 {

class MostStonesRemovedWithSameRowOrColumnTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override {
    solution_.setStrategy(GetParam());
  }

  MostStonesRemovedWithSameRowOrColumnSolution solution_;
};

TEST_P(MostStonesRemovedWithSameRowOrColumnTest, Example1) {
  std::vector<std::vector<int>> stones = {
      {0, 0}, {0, 1}, {1, 0}, {1, 2}, {2, 1}, {2, 2}};
  EXPECT_EQ(solution_.removeStones(stones), 5);
}

TEST_P(MostStonesRemovedWithSameRowOrColumnTest, Example2) {
  std::vector<std::vector<int>> stones = {
      {0, 0}, {0, 2}, {1, 1}, {2, 0}, {2, 2}};
  EXPECT_EQ(solution_.removeStones(stones), 3);
}

TEST_P(MostStonesRemovedWithSameRowOrColumnTest, Example3) {
  std::vector<std::vector<int>> stones = {{0, 0}};
  EXPECT_EQ(solution_.removeStones(stones), 0);
}

TEST_P(MostStonesRemovedWithSameRowOrColumnTest, SelfAuthoredTwoIndependentStones) {
  std::vector<std::vector<int>> stones = {{0, 0}, {1, 1}};
  EXPECT_EQ(solution_.removeStones(stones), 0);
}

TEST_P(MostStonesRemovedWithSameRowOrColumnTest, SelfAuthoredTwoStonesShareRow) {
  std::vector<std::vector<int>> stones = {{0, 0}, {0, 1}};
  EXPECT_EQ(solution_.removeStones(stones), 1);
}

INSTANTIATE_TEST_SUITE_P(
    MostStonesRemovedWithSameRowOrColumnTestSuite,
    MostStonesRemovedWithSameRowOrColumnTest,
    ::testing::ValuesIn(
        MostStonesRemovedWithSameRowOrColumnSolution().getStrategyNames()));

}  // namespace leetcode::problem_947
