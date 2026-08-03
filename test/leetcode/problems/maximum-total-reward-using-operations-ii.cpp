#include <gtest/gtest.h>

#include "leetcode/problems/maximum-total-reward-using-operations-ii.h"

#include <string>
#include <vector>

namespace leetcode {
namespace problem_3181 {

class MaximumTotalRewardUsingOperationsIiTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  MaximumTotalRewardUsingOperationsIiSolution solution_;
};

TEST_P(MaximumTotalRewardUsingOperationsIiTest, Example1) {
  std::vector<int> rewardValues{1, 1, 3, 3};
  EXPECT_EQ(4, solution_.maxTotalReward(rewardValues));
}

TEST_P(MaximumTotalRewardUsingOperationsIiTest, Example2) {
  std::vector<int> rewardValues{1, 6, 4, 3, 2};
  EXPECT_EQ(11, solution_.maxTotalReward(rewardValues));
}

TEST_P(MaximumTotalRewardUsingOperationsIiTest, SelfAuthoredSingleValue) {
  std::vector<int> rewardValues{7};
  EXPECT_EQ(7, solution_.maxTotalReward(rewardValues));
}

TEST_P(MaximumTotalRewardUsingOperationsIiTest, SelfAuthoredAllSame) {
  std::vector<int> rewardValues{5, 5, 5};
  EXPECT_EQ(5, solution_.maxTotalReward(rewardValues));
}

TEST_P(MaximumTotalRewardUsingOperationsIiTest, SelfAuthoredSortedAscending) {
  std::vector<int> rewardValues{1, 2, 3, 4};
  // 1 -> x=1; 2(>1) -> 3; 4(>3) -> 7。
  EXPECT_EQ(7, solution_.maxTotalReward(rewardValues));
}

INSTANTIATE_TEST_SUITE_P(
    MaximumTotalRewardUsingOperationsIiParameters,
    MaximumTotalRewardUsingOperationsIiTest,
    ::testing::ValuesIn(
        MaximumTotalRewardUsingOperationsIiSolution().getStrategyNames()));

}  // namespace problem_3181
}  // namespace leetcode
