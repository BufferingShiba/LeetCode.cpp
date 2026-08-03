#include <gtest/gtest.h>

#include "leetcode/problems/jump-game-ii.h"

#include <string>
#include <vector>

namespace leetcode {
namespace problem_45 {

class JumpGameIiTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  JumpGameIiSolution solution;
};

TEST_P(JumpGameIiTest, Example1) {
  std::vector<int> nums{2, 3, 1, 1, 4};
  EXPECT_EQ(2, solution.jump(nums));
}

TEST_P(JumpGameIiTest, Example2) {
  std::vector<int> nums{2, 3, 0, 1, 4};
  EXPECT_EQ(2, solution.jump(nums));
}

TEST_P(JumpGameIiTest, SelfAuthoredSingleElement) {
  std::vector<int> nums{0};
  EXPECT_EQ(0, solution.jump(nums));
}

TEST_P(JumpGameIiTest, SelfAuthoredTwoElements) {
  std::vector<int> nums{1, 0};
  EXPECT_EQ(1, solution.jump(nums));
}

TEST_P(JumpGameIiTest, SelfAuthoredAllOnes) {
  std::vector<int> nums{1, 1, 1, 1};
  EXPECT_EQ(3, solution.jump(nums));
}

INSTANTIATE_TEST_SUITE_P(
    JumpGameIiTestSuite, JumpGameIiTest,
    ::testing::ValuesIn(JumpGameIiSolution().getStrategyNames()));

}  // namespace problem_45
}  // namespace leetcode
