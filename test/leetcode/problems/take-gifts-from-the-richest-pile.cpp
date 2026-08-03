#include "leetcode/problems/take-gifts-from-the-richest-pile.h"

#include <gtest/gtest.h>

#include <string>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_2558 {
namespace test {

class TakeGiftsFromTheRichestPileTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  TakeGiftsFromTheRichestPileSolution solution_;
};

TEST_P(TakeGiftsFromTheRichestPileTest, Example1) {
  std::vector<int> gifts = {25, 64, 9, 4, 100};
  EXPECT_EQ(29, solution_.pickGifts(gifts, 4));
}

TEST_P(TakeGiftsFromTheRichestPileTest, Example2) {
  std::vector<int> gifts = {1, 1, 1, 1};
  EXPECT_EQ(4, solution_.pickGifts(gifts, 4));
}

TEST_P(TakeGiftsFromTheRichestPileTest, SinglePile) {
  std::vector<int> gifts = {100};
  EXPECT_EQ(10, solution_.pickGifts(gifts, 1));
}

INSTANTIATE_TEST_SUITE_P(
    TakeGiftsFromTheRichestPileTests, TakeGiftsFromTheRichestPileTest,
    ::testing::ValuesIn(TakeGiftsFromTheRichestPileSolution().getStrategyNames()));

}  // namespace test
}  // namespace problem_2558
}  // namespace leetcode
