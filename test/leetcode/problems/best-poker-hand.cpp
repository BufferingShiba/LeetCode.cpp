#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/best-poker-hand.h"

namespace leetcode {
namespace problem_2347 {

class BestPokerHandTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  BestPokerHandSolution solution;
};

TEST_P(BestPokerHandTest, Example1Flush) {
  std::vector<int> ranks = {13, 2, 3, 1, 9};
  std::vector<char> suits = {'a', 'a', 'a', 'a', 'a'};
  EXPECT_EQ("Flush", solution.bestHand(ranks, suits));
}

TEST_P(BestPokerHandTest, Example2ThreeOfAKind) {
  std::vector<int> ranks = {4, 4, 2, 4, 4};
  std::vector<char> suits = {'d', 'a', 'a', 'b', 'c'};
  EXPECT_EQ("Three of a Kind", solution.bestHand(ranks, suits));
}

TEST_P(BestPokerHandTest, Example3Pair) {
  std::vector<int> ranks = {10, 10, 2, 12, 9};
  std::vector<char> suits = {'a', 'b', 'c', 'a', 'd'};
  EXPECT_EQ("Pair", solution.bestHand(ranks, suits));
}

TEST_P(BestPokerHandTest, SelfAuthoredHighCard) {
  std::vector<int> ranks = {1, 2, 3, 4, 5};
  std::vector<char> suits = {'a', 'b', 'c', 'a', 'd'};
  EXPECT_EQ("High Card", solution.bestHand(ranks, suits));
}

INSTANTIATE_TEST_SUITE_P(
    BestPokerHandTestSuite,
    BestPokerHandTest,
    ::testing::ValuesIn(BestPokerHandSolution().getStrategyNames()));

}  // namespace problem_2347
}  // namespace leetcode
