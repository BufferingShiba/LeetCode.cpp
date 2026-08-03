#include <gtest/gtest.h>

#include <vector>

#include "leetcode/problems/jump-game.h"

namespace leetcode {
namespace problem_55 {

class JumpGameTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  JumpGameSolution solution_;
};

TEST_P(JumpGameTest, OfficialExample1) {
  std::vector<int> nums = {2, 3, 1, 1, 4};
  EXPECT_TRUE(solution_.canJump(nums));
}

TEST_P(JumpGameTest, OfficialExample2) {
  std::vector<int> nums = {3, 2, 1, 0, 4};
  EXPECT_FALSE(solution_.canJump(nums));
}

TEST_P(JumpGameTest, SelfAuthoredSingleElement) {
  std::vector<int> nums = {0};
  EXPECT_TRUE(solution_.canJump(nums));
}

TEST_P(JumpGameTest, SelfAuthoredSingleElementNonZero) {
  std::vector<int> nums = {5};
  EXPECT_TRUE(solution_.canJump(nums));
}

TEST_P(JumpGameTest, SelfAuthoredAllZerosExceptStart) {
  std::vector<int> nums = {3, 0, 0, 0};
  EXPECT_TRUE(solution_.canJump(nums));
}

TEST_P(JumpGameTest, SelfAuthoredStuckAtZero) {
  std::vector<int> nums = {1, 0, 1, 0};
  EXPECT_FALSE(solution_.canJump(nums));
}

TEST_P(JumpGameTest, SelfAuthoredLargeJumpAtStart) {
  std::vector<int> nums = {10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  EXPECT_TRUE(solution_.canJump(nums));
}

INSTANTIATE_TEST_SUITE_P(, JumpGameTest,
                         ::testing::ValuesIn(JumpGameSolution().getStrategyNames()));

}  // namespace problem_55
}  // namespace leetcode
