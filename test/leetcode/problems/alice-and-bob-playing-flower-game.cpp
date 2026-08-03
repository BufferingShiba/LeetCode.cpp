#include <gtest/gtest.h>
#include "leetcode/problems/alice-and-bob-playing-flower-game.h"

namespace leetcode {
namespace problem_3021 {

class AliceAndBobPlayingFlowerGameTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override {
    solution_.setStrategy(GetParam());
  }
  AliceAndBobPlayingFlowerGameSolution solution_;
};

TEST_P(AliceAndBobPlayingFlowerGameTest, Example1) {
  EXPECT_EQ(solution_.flowerGame(3, 2), 3);
}

TEST_P(AliceAndBobPlayingFlowerGameTest, Example2) {
  EXPECT_EQ(solution_.flowerGame(1, 1), 0);
}

TEST_P(AliceAndBobPlayingFlowerGameTest, SelfAuthoredBothEven) {
  // n=4: odd=2, even=2; m=4: odd=2, even=2 => 2*2 + 2*2 = 8
  EXPECT_EQ(solution_.flowerGame(4, 4), 8);
}

TEST_P(AliceAndBobPlayingFlowerGameTest, SelfAuthoredN1M2) {
  // n=1: odd=1, even=0; m=2: odd=1, even=1 => 1*1 + 0*1 = 1 (pair: (1,2))
  EXPECT_EQ(solution_.flowerGame(1, 2), 1);
}

INSTANTIATE_TEST_SUITE_P(
    , AliceAndBobPlayingFlowerGameTest,
    ::testing::ValuesIn(AliceAndBobPlayingFlowerGameSolution().getStrategyNames()));

}  // namespace problem_3021
}  // namespace leetcode
