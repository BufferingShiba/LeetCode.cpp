#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/eliminate-maximum-number-of-monsters.h"

namespace leetcode {
namespace problem_1921 {
namespace {

class EliminateMaximumNumberOfMonstersTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override {
    solution.setStrategy(GetParam());
  }

  EliminateMaximumNumberOfMonstersSolution solution;
};

TEST_P(EliminateMaximumNumberOfMonstersTest, Example1) {
  std::vector<int> dist = {1, 3, 4};
  std::vector<int> speed = {1, 1, 1};
  EXPECT_EQ(3, solution.eliminateMaximum(dist, speed));
}

TEST_P(EliminateMaximumNumberOfMonstersTest, Example2) {
  std::vector<int> dist = {1, 1, 2, 3};
  std::vector<int> speed = {1, 1, 1, 1};
  EXPECT_EQ(1, solution.eliminateMaximum(dist, speed));
}

TEST_P(EliminateMaximumNumberOfMonstersTest, Example3) {
  std::vector<int> dist = {3, 2, 4};
  std::vector<int> speed = {5, 3, 2};
  EXPECT_EQ(1, solution.eliminateMaximum(dist, speed));
}

TEST_P(EliminateMaximumNumberOfMonstersTest, SelfAuthoredSingleMonster) {
  std::vector<int> dist = {5};
  std::vector<int> speed = {1};
  EXPECT_EQ(1, solution.eliminateMaximum(dist, speed));
}

TEST_P(EliminateMaximumNumberOfMonstersTest, SelfAuthoredFractionalArrival) {
  // arrival = ceil(d/s): [1, 2, 3] -> all killable.
  std::vector<int> dist = {1, 3, 5};
  std::vector<int> speed = {1, 2, 2};
  EXPECT_EQ(3, solution.eliminateMaximum(dist, speed));
}

INSTANTIATE_TEST_SUITE_P(
    EliminateMaximumNumberOfMonstersTestSuite, EliminateMaximumNumberOfMonstersTest,
    ::testing::ValuesIn(EliminateMaximumNumberOfMonstersSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_1921
}  // namespace leetcode
