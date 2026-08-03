#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/moving-stones-until-consecutive-ii.h"

namespace leetcode::problem_1040 {
namespace {

class MovingStonesUntilConsecutiveIiTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  MovingStonesUntilConsecutiveIiSolution solution_;
};

TEST_P(MovingStonesUntilConsecutiveIiTest, Example1) {
  std::vector<int> stones{7, 4, 9};
  EXPECT_EQ(solution_.numMovesStonesII(stones), (std::vector<int>{1, 2}));
}

TEST_P(MovingStonesUntilConsecutiveIiTest, Example2) {
  std::vector<int> stones{6, 5, 4, 3, 10};
  EXPECT_EQ(solution_.numMovesStonesII(stones), (std::vector<int>{2, 3}));
}

TEST_P(MovingStonesUntilConsecutiveIiTest, AlreadyConsecutive) {
  std::vector<int> stones{1, 2, 3};
  EXPECT_EQ(solution_.numMovesStonesII(stones), (std::vector<int>{0, 0}));
}

TEST_P(MovingStonesUntilConsecutiveIiTest, ClassicTrickyCase) {
  // n-1 stones already consecutive -> minimum is 2 moves.
  // Max = max(stones[3]-stones[0], stones[4]-stones[1]) - 3
  //     = max(3, 8) - 3 = 5.
  std::vector<int> stones{1, 2, 3, 4, 10};
  EXPECT_EQ(solution_.numMovesStonesII(stones), (std::vector<int>{2, 5}));
}

TEST_P(MovingStonesUntilConsecutiveIiTest, FourEvenlySpaced) {
  // [1,3,5,7]: min=2, max=max(4,4)-2=2.
  std::vector<int> stones{1, 3, 5, 7};
  EXPECT_EQ(solution_.numMovesStonesII(stones), (std::vector<int>{2, 2}));
}

INSTANTIATE_TEST_SUITE_P(
    MovingStonesUntilConsecutiveIiSuites, MovingStonesUntilConsecutiveIiTest,
    ::testing::ValuesIn(
        MovingStonesUntilConsecutiveIiSolution().getStrategyNames()));

}  // namespace
}  // namespace leetcode::problem_1040
