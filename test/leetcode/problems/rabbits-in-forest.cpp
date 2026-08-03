#include <gtest/gtest.h>
#include <vector>
#include <string>

#include "leetcode/problems/rabbits-in-forest.h"

namespace leetcode {
namespace problem_781 {

class RabbitsInForestTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override {
    solution.setStrategy(GetParam());
  }
  RabbitsInForestSolution solution;
};

TEST_P(RabbitsInForestTest, Example1) {
  std::vector<int> answers = {1, 1, 2};
  EXPECT_EQ(5, solution.numRabbits(answers));
}

TEST_P(RabbitsInForestTest, Example2) {
  std::vector<int> answers = {10, 10, 10};
  EXPECT_EQ(11, solution.numRabbits(answers));
}

TEST_P(RabbitsInForestTest, SelfAuthoredSingleRabbitNoOthers) {
  std::vector<int> answers = {0};
  EXPECT_EQ(1, solution.numRabbits(answers));
}

TEST_P(RabbitsInForestTest, SelfAuthoredTwoRabbitsSameColor) {
  std::vector<int> answers = {1, 1, 1};
  EXPECT_EQ(4, solution.numRabbits(answers));
}

INSTANTIATE_TEST_SUITE_P(
    RabbitsInForestStrategies,
    RabbitsInForestTest,
    ::testing::ValuesIn(RabbitsInForestSolution().getStrategyNames()));

}  // namespace problem_781
}  // namespace leetcode
