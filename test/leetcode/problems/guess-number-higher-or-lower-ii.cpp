#include <gtest/gtest.h>
#include "leetcode/problems/guess-number-higher-or-lower-ii.h"

namespace leetcode {
namespace problem_375 {
namespace test {

class GuessNumberHigherOrLowerIiTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  GuessNumberHigherOrLowerIiSolution solution;
};

TEST_P(GuessNumberHigherOrLowerIiTest, Example1) {
  EXPECT_EQ(solution.getMoneyAmount(10), 16);
}

TEST_P(GuessNumberHigherOrLowerIiTest, Example2) {
  EXPECT_EQ(solution.getMoneyAmount(1), 0);
}

TEST_P(GuessNumberHigherOrLowerIiTest, Example3) {
  EXPECT_EQ(solution.getMoneyAmount(2), 1);
}

TEST_P(GuessNumberHigherOrLowerIiTest, SelfAuthoredN3) {
  // n=3: guess 2 pays 2 in worst case (min strategy).
  EXPECT_EQ(solution.getMoneyAmount(3), 2);
}

INSTANTIATE_TEST_SUITE_P(
    GuessNumberHigherOrLowerIiSuite, GuessNumberHigherOrLowerIiTest,
    ::testing::ValuesIn(GuessNumberHigherOrLowerIiSolution().getStrategyNames()));

}  // namespace test
}  // namespace problem_375
}  // namespace leetcode
