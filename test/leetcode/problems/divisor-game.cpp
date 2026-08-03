#include <gtest/gtest.h>

#include "leetcode/problems/divisor-game.h"

namespace leetcode {
namespace problem_1025 {

class DivisorGameTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  DivisorGameSolution solution_;
};

TEST_P(DivisorGameTest, OfficialExamples) {
  // Example 1: n=2 → Alice wins
  EXPECT_TRUE(solution_.divisorGame(2));
  // Example 2: n=3 → Alice loses
  EXPECT_FALSE(solution_.divisorGame(3));
}

TEST_P(DivisorGameTest, SelfAuthored) {
  // n=1: no valid x, Alice loses immediately
  EXPECT_FALSE(solution_.divisorGame(1));

  // n=4: Alice picks x=1, n→3 (Bob loses), Alice wins
  EXPECT_TRUE(solution_.divisorGame(4));

  // n=6: even → Alice wins
  EXPECT_TRUE(solution_.divisorGame(6));
}

INSTANTIATE_TEST_SUITE_P(Strategies, DivisorGameTest,
                         ::testing::ValuesIn(DivisorGameSolution().getStrategyNames()));

}  // namespace problem_1025
}  // namespace leetcode
