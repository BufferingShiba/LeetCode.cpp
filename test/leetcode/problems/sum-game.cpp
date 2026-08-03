#include "leetcode/problems/sum-game.h"

#include <gtest/gtest.h>

#include <string>
#include <vector>

namespace leetcode {
namespace problem_1927 {
namespace {

class SumGameTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  SumGameSolution solution_;
};

TEST_P(SumGameTest, Example1) {
  EXPECT_FALSE(solution_.getSolution()("5023"));
}

TEST_P(SumGameTest, Example2) {
  EXPECT_TRUE(solution_.getSolution()("25??"));
}

TEST_P(SumGameTest, Example3) {
  EXPECT_FALSE(solution_.getSolution()("?3295???"));
}

TEST_P(SumGameTest, AllKnownUnequal) {
  EXPECT_TRUE(solution_.getSolution()("1243"));
}

TEST_P(SumGameTest, SingleQuestionOdd) {
  EXPECT_TRUE(solution_.getSolution()("1?"));
}

TEST_P(SumGameTest, EvenCountBalanced) {
  EXPECT_TRUE(solution_.getSolution()("01??"));
}

INSTANTIATE_TEST_SUITE_P(SumGameStrategies, SumGameTest,
                         ::testing::ValuesIn(SumGameSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_1927
}  // namespace leetcode
