#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/baseball-game.h"

namespace leetcode::problem_682 {

class BaseballGameTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  BaseballGameSolution solution;
};

TEST_P(BaseballGameTest, Example1) {
  std::vector<std::string> ops = {"5", "2", "C", "D", "+"};
  EXPECT_EQ(solution.calPoints(ops), 30);
}

TEST_P(BaseballGameTest, Example2) {
  std::vector<std::string> ops = {"5", "-2", "4", "C", "D", "9", "+", "+"};
  EXPECT_EQ(solution.calPoints(ops), 27);
}

TEST_P(BaseballGameTest, Example3) {
  std::vector<std::string> ops = {"1", "C"};
  EXPECT_EQ(solution.calPoints(ops), 0);
}

TEST_P(BaseballGameTest, SelfAuthored) {
  // All integers
  std::vector<std::string> ops1 = {"10", "20", "30"};
  EXPECT_EQ(solution.calPoints(ops1), 60);

  // Only D and integers
  std::vector<std::string> ops2 = {"3", "D", "D"};
  EXPECT_EQ(solution.calPoints(ops2), 21);

  // Mixed with negative
  std::vector<std::string> ops3 = {"-5", "10", "+", "D", "C"};
  EXPECT_EQ(solution.calPoints(ops3), 10);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    BaseballGameTest,
    ::testing::ValuesIn(BaseballGameSolution().getStrategyNames()));

}  // namespace leetcode::problem_682
