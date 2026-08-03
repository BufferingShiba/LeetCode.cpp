#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/jump-game-vi.h"

namespace leetcode {
namespace problem_1696 {

using leetcode::problem_1696::JumpGameViSolution;

class JumpGameViTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  JumpGameViSolution solution;
};

TEST_P(JumpGameViTest, Example1) {
  std::vector<int> nums = {1, -1, -2, 4, -7, 3};
  int k = 2;
  EXPECT_EQ(7, solution.getSolution()(nums, k));
}

TEST_P(JumpGameViTest, Example2) {
  std::vector<int> nums = {10, -5, -2, 4, 0, 3};
  int k = 3;
  EXPECT_EQ(17, solution.getSolution()(nums, k));
}

TEST_P(JumpGameViTest, Example3) {
  std::vector<int> nums = {1, -5, -20, 4, -1, 3, -6, -3};
  int k = 2;
  EXPECT_EQ(0, solution.getSolution()(nums, k));
}

TEST_P(JumpGameViTest, SelfAuthoredSingleElement) {
  std::vector<int> nums = {5};
  int k = 3;
  EXPECT_EQ(5, solution.getSolution()(nums, k));
}

TEST_P(JumpGameViTest, SelfAuthoredTwoElements) {
  std::vector<int> nums = {3, -1};
  int k = 1;
  EXPECT_EQ(2, solution.getSolution()(nums, k));
}

INSTANTIATE_TEST_SUITE_P(
    JumpGameViTestSuite, JumpGameViTest,
    ::testing::ValuesIn(JumpGameViSolution().getStrategyNames()));

}  // namespace problem_1696
}  // namespace leetcode
