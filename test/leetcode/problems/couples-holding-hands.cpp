#include <gtest/gtest.h>

#include "leetcode/problems/couples-holding-hands.h"

namespace leetcode::problem_765 {

class CouplesHoldingHandsTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }
  CouplesHoldingHandsSolution solution_;
};

TEST_P(CouplesHoldingHandsTest, Example1) {
  std::vector<int> row = {0, 2, 1, 3};
  EXPECT_EQ(solution_.minSwapsCouples(row), 1);
}

TEST_P(CouplesHoldingHandsTest, Example2) {
  std::vector<int> row = {3, 2, 0, 1};
  EXPECT_EQ(solution_.minSwapsCouples(row), 0);
}

TEST_P(CouplesHoldingHandsTest, SelfAuthoredAllAlreadyAdjacent) {
  std::vector<int> row = {0, 1, 2, 3, 4, 5};
  EXPECT_EQ(solution_.minSwapsCouples(row), 0);
}

TEST_P(CouplesHoldingHandsTest, SelfAuthoredThreeCoupleCycle) {
  std::vector<int> row = {0, 4, 1, 2, 5, 3};
  EXPECT_EQ(solution_.minSwapsCouples(row), 2);
}

TEST_P(CouplesHoldingHandsTest, SelfAuthoredSinglePair) {
  std::vector<int> row = {1, 0};
  EXPECT_EQ(solution_.minSwapsCouples(row), 0);
}

TEST_P(CouplesHoldingHandsTest, SelfAuthoredReversedPair) {
  std::vector<int> row = {2, 0, 1, 3};
  EXPECT_EQ(solution_.minSwapsCouples(row), 1);
}

INSTANTIATE_TEST_SUITE_P(Strategies, CouplesHoldingHandsTest,
                         ::testing::ValuesIn(
                             CouplesHoldingHandsSolution().getStrategyNames()));

}  // namespace leetcode::problem_765
