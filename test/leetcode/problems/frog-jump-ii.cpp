#include "leetcode/problems/frog-jump-ii.h"

#include <gtest/gtest.h>

#include <string>
#include <vector>

namespace leetcode {
namespace problem_2498 {
namespace {

class FrogJumpIiTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  FrogJumpIiSolution solution;
};

TEST_P(FrogJumpIiTest, Example1) {
  std::vector<int> stones = {0, 2, 5, 6, 7};
  EXPECT_EQ(5, solution.maxJump(stones));
}

TEST_P(FrogJumpIiTest, Example2) {
  std::vector<int> stones = {0, 3, 9};
  EXPECT_EQ(9, solution.maxJump(stones));
}

TEST_P(FrogJumpIiTest, SelfAuthoredTwoStones) {
  std::vector<int> stones = {0, 10};
  EXPECT_EQ(10, solution.maxJump(stones));
}

TEST_P(FrogJumpIiTest, SelfAuthoredFourStones) {
  // Forward: 0 -> stones[2] -> stones[3]; Back: stones[1] -> 0.
  // max = max(stones[1]-stones[0], stones[3]-stones[2], stones[2]-stones[0],
  //           stones[3]-stones[1])
  std::vector<int> stones = {0, 1, 100, 101};
  EXPECT_EQ(100, solution.maxJump(stones));
}

INSTANTIATE_TEST_SUITE_P(
    FrogJumpIiStrategies, FrogJumpIiTest,
    ::testing::ValuesIn(FrogJumpIiSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_2498
}  // namespace leetcode
