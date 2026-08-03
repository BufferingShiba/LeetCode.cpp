#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/snake-in-matrix.h"

namespace leetcode {
namespace problem_3248 {
namespace {

class SnakeInMatrixTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  SnakeInMatrixSolution solution_;
};

TEST_P(SnakeInMatrixTest, Example1) {
  int n = 2;
  std::vector<std::string> commands = {"RIGHT", "DOWN"};
  EXPECT_EQ(3, solution_.finalPositionOfSnake(n, commands));
}

TEST_P(SnakeInMatrixTest, Example2) {
  int n = 3;
  std::vector<std::string> commands = {"DOWN", "RIGHT", "UP"};
  EXPECT_EQ(1, solution_.finalPositionOfSnake(n, commands));
}

TEST_P(SnakeInMatrixTest, SelfAuthoredEmptyCommands) {
  int n = 2;
  std::vector<std::string> commands = {};
  EXPECT_EQ(0, solution_.finalPositionOfSnake(n, commands));
}

INSTANTIATE_TEST_SUITE_P(
    SnakeInMatrixTestSuite, SnakeInMatrixTest,
    ::testing::ValuesIn(SnakeInMatrixSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_3248
}  // namespace leetcode
