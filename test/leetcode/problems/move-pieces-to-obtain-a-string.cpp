#include <gtest/gtest.h>

#include "leetcode/problems/move-pieces-to-obtain-a-string.h"

namespace leetcode {
namespace problem_2337 {

class MovePiecesToObtainAStringTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  MovePiecesToObtainAStringSolution solution_;
};

TEST_P(MovePiecesToObtainAStringTest, Example1) {
  EXPECT_TRUE(solution_.canChange("_L__R__R_", "L______RR"));
}

TEST_P(MovePiecesToObtainAStringTest, Example2) {
  EXPECT_FALSE(solution_.canChange("R_L_", "__LR"));
}

TEST_P(MovePiecesToObtainAStringTest, Example3) {
  EXPECT_FALSE(solution_.canChange("_R", "R_"));
}

TEST_P(MovePiecesToObtainAStringTest, SelfAuthored) {
  // Already identical
  EXPECT_TRUE(solution_.canChange("L_R", "L_R"));
  // All blanks
  EXPECT_TRUE(solution_.canChange("___", "___"));
  // Single L can move left
  EXPECT_TRUE(solution_.canChange("_L", "L_"));
  // L cannot move right
  EXPECT_FALSE(solution_.canChange("L_", "_L"));
  // Single R can move right
  EXPECT_TRUE(solution_.canChange("R_", "_R"));
  // R cannot move left
  EXPECT_FALSE(solution_.canChange("_R", "R_"));
  // Pieces would need to cross
  EXPECT_FALSE(solution_.canChange("LR", "RL"));
  // Longer case: multiple moves
  EXPECT_TRUE(solution_.canChange("__L__R__", "L____R__"));
}

INSTANTIATE_TEST_SUITE_P(Strategies, MovePiecesToObtainAStringTest,
                         ::testing::ValuesIn(
                             MovePiecesToObtainAStringSolution().getStrategyNames()));

}  // namespace problem_2337
}  // namespace leetcode
