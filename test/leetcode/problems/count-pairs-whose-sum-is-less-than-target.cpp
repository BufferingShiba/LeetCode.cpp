#include "leetcode/problems/count-pairs-whose-sum-is-less-than-target.h"

#include <gtest/gtest.h>

namespace leetcode {
namespace problem_2824 {
namespace {

class CountPairsWhoseSumIsLessThanTargetTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  CountPairsWhoseSumIsLessThanTargetSolution solution;
};

TEST_P(CountPairsWhoseSumIsLessThanTargetTest, Example1) {
  std::vector<int> nums{-1, 1, 2, 3, 1};
  EXPECT_EQ(solution.countPairs(nums, 2), 3);
}

TEST_P(CountPairsWhoseSumIsLessThanTargetTest, Example2) {
  std::vector<int> nums{-6, 2, 5, -2, -7, -1, 3};
  EXPECT_EQ(solution.countPairs(nums, -2), 10);
}

TEST_P(CountPairsWhoseSumIsLessThanTargetTest, SelfAuthoredSingleElement) {
  std::vector<int> nums{5};
  EXPECT_EQ(solution.countPairs(nums, 10), 0);
}

INSTANTIATE_TEST_SUITE_P(
    CountPairsWhoseSumIsLessThanTargetTestSuite,
    CountPairsWhoseSumIsLessThanTargetTest,
    ::testing::ValuesIn(CountPairsWhoseSumIsLessThanTargetSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_2824
}  // namespace leetcode
