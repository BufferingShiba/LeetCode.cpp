#include <gtest/gtest.h>
#include "leetcode/problems/water-bottles.h"

namespace leetcode {
namespace problem_1518 {

class WaterBottlesTest : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override {
    solution_.setStrategy(GetParam());
  }

  WaterBottlesSolution solution_;
};

TEST_P(WaterBottlesTest, Example1) {
  EXPECT_EQ(solution_.numWaterBottles(9, 3), 13);
}

TEST_P(WaterBottlesTest, Example2) {
  EXPECT_EQ(solution_.numWaterBottles(15, 4), 19);
}

TEST_P(WaterBottlesTest, SelfAuthoredNotEnoughToExchange) {
  EXPECT_EQ(solution_.numWaterBottles(1, 2), 1);
}

TEST_P(WaterBottlesTest, SelfAuthoredExactExchange) {
  EXPECT_EQ(solution_.numWaterBottles(2, 2), 3);
}

TEST_P(WaterBottlesTest, SelfAuthoredLargeCase) {
  // numBottles=100, numExchange=2 -> 100+50+25+12+6+3+2+1 = 199
  EXPECT_EQ(solution_.numWaterBottles(100, 2), 199);
}

INSTANTIATE_TEST_SUITE_P(,
                         WaterBottlesTest,
                         testing::ValuesIn(WaterBottlesSolution().getStrategyNames()));

}  // namespace problem_1518
}  // namespace leetcode
