#include <gtest/gtest.h>

#include "leetcode/problems/reverse-pairs.h"

using namespace leetcode::problem_493;

class ReversePairsTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  ReversePairsSolution solution;
};

TEST_P(ReversePairsTest, Example1) {
  std::vector<int> nums = {1, 3, 2, 3, 1};
  EXPECT_EQ(solution.reversePairs(nums), 2);
}

TEST_P(ReversePairsTest, Example2) {
  std::vector<int> nums = {2, 4, 3, 5, 1};
  EXPECT_EQ(solution.reversePairs(nums), 3);
}

TEST_P(ReversePairsTest, SelfAuthoredSingleElement) {
  std::vector<int> nums = {5};
  EXPECT_EQ(solution.reversePairs(nums), 0);
}

TEST_P(ReversePairsTest, SelfAuthoredNoReversePair) {
  std::vector<int> nums = {1, 2, 3, 4, 5};
  EXPECT_EQ(solution.reversePairs(nums), 0);
}

TEST_P(ReversePairsTest, SelfAuthoredAllReversePairs) {
  std::vector<int> nums = {5, 4, 3, 2, 1};
  // (0,3): 5>2*2=4 ✓ | (0,4): 5>2*1=2 ✓ | (1,4): 4>2*1=2 ✓ | (2,4): 3>2*1=2 ✓
  EXPECT_EQ(solution.reversePairs(nums), 4);
}

TEST_P(ReversePairsTest, SelfAuthoredNegativeNumbers) {
  std::vector<int> nums = {-5, -5};
  // -5 > 2*(-5) = -10  → true
  EXPECT_EQ(solution.reversePairs(nums), 1);
}

INSTANTIATE_TEST_SUITE_P(Strategies, ReversePairsTest,
                         ::testing::ValuesIn(ReversePairsSolution().getStrategyNames()));
