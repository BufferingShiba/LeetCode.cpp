#include <gtest/gtest.h>

#include <vector>

#include "leetcode/problems/hand-of-straights.h"

using namespace leetcode::problem_846;

class HandOfStraightsTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  HandOfStraightsSolution solution;
};

TEST_P(HandOfStraightsTest, OfficialExamples) {
  // Example 1
  {
    std::vector<int> hand = {1, 2, 3, 6, 2, 3, 4, 7, 8};
    EXPECT_TRUE(solution.isNStraightHand(hand, 3));
  }
  // Example 2
  {
    std::vector<int> hand = {1, 2, 3, 4, 5};
    EXPECT_FALSE(solution.isNStraightHand(hand, 4));
  }
}

TEST_P(HandOfStraightsTest, SelfAuthored) {
  // groupSize = 1: always true
  {
    std::vector<int> hand = {5, 1, 3, 9};
    EXPECT_TRUE(solution.isNStraightHand(hand, 1));
  }
  // groupSize equals hand size, must be consecutive
  {
    std::vector<int> hand = {3, 4, 5, 6};
    EXPECT_TRUE(solution.isNStraightHand(hand, 4));
  }
  {
    std::vector<int> hand = {3, 5, 6, 7};
    EXPECT_FALSE(solution.isNStraightHand(hand, 4));
  }
  // Duplicates causing failure
  {
    std::vector<int> hand = {1, 2, 2, 3, 3, 4};
    EXPECT_TRUE(solution.isNStraightHand(hand, 3));
  }
  {
    std::vector<int> hand = {1, 2, 2, 3, 4, 5};
    EXPECT_FALSE(solution.isNStraightHand(hand, 3));
  }
}

INSTANTIATE_TEST_SUITE_P(
    AllStrategies,
    HandOfStraightsTest,
    ::testing::ValuesIn(HandOfStraightsSolution().getStrategyNames()));
