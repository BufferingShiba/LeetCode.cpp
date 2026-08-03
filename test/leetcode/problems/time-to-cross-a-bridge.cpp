#include "leetcode/problems/time-to-cross-a-bridge.h"

#include <gtest/gtest.h>

namespace leetcode {
namespace problem_2532 {

class TimeToCrossABridgeTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }
  TimeToCrossABridgeSolution solution;
};

TEST_P(TimeToCrossABridgeTest, Example1) {
  int n = 1, k = 3;
  std::vector<std::vector<int>> time = {{1, 1, 2, 1}, {1, 1, 3, 1}, {1, 1, 4, 1}};
  EXPECT_EQ(solution.findCrossingTime(n, k, time), 6);
}

TEST_P(TimeToCrossABridgeTest, Example2) {
  int n = 3, k = 2;
  std::vector<std::vector<int>> time = {{1, 5, 1, 8}, {10, 10, 10, 10}};
  EXPECT_EQ(solution.findCrossingTime(n, k, time), 37);
}

TEST_P(TimeToCrossABridgeTest, SelfAuthoredSingleWorker) {
  int n = 5, k = 1;
  std::vector<std::vector<int>> time = {{2, 3, 4, 5}};
  // Worker must cross back and forth 5 times. Each round trip across bridge = right+left = 2+4.
  // Path: left->right(2) pick(3) right->left(4) -> carries a box (arrive left), then put(5) then repeat.
  // arriveLeft events at: 2+4=6, then each next crossing cycle adds right(2)+(repeat). Actually:
  // t0: cross right 0->2, pick 2->5, cross left 5->9 (arriveLeft#1), put 9->14, cross right 14->16, pick 16->19,
  //     cross left 19->23 (arriveLeft#2), put 23->28, cross right 28->30, pick 30->33, cross left 33->37
  //     (arriveLeft#3), put 37->42, cross right 42->44, pick 44->47, cross left 47->51 (arriveLeft#4),
  //     put 51->56, cross right 56->58, pick 58->61, cross left 61->65 (arriveLeft#5).
  EXPECT_EQ(solution.findCrossingTime(n, k, time), 65);
}

INSTANTIATE_TEST_SUITE_P(
    TimeToCrossABridgeTestSuite, TimeToCrossABridgeTest,
    ::testing::ValuesIn(TimeToCrossABridgeSolution().getStrategyNames()));

}  // namespace problem_2532
}  // namespace leetcode
