#include <gtest/gtest.h>

#include "leetcode/problems/count-collisions-of-monkeys-on-a-polygon.h"

namespace leetcode::problem_2550 {

class CountCollisionsOfMonkeysOnAPolygonTest
    : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  CountCollisionsOfMonkeysOnAPolygonSolution solution_;
};

TEST_P(CountCollisionsOfMonkeysOnAPolygonTest, Examples) {
  EXPECT_EQ(solution_.monkeyMove(3), 6);
  EXPECT_EQ(solution_.monkeyMove(4), 14);
}

TEST_P(CountCollisionsOfMonkeysOnAPolygonTest, SelfAuthored) {
  // n = 5: 2^5 - 2 = 32 - 2 = 30
  EXPECT_EQ(solution_.monkeyMove(5), 30);
  // n = 6: 2^6 - 2 = 64 - 2 = 62
  EXPECT_EQ(solution_.monkeyMove(6), 62);
  // n = 10: 2^10 - 2 = 1024 - 2 = 1022
  EXPECT_EQ(solution_.monkeyMove(10), 1022);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    CountCollisionsOfMonkeysOnAPolygonTest,
    testing::ValuesIn(
        CountCollisionsOfMonkeysOnAPolygonSolution().getStrategyNames()));

}  // namespace leetcode::problem_2550
