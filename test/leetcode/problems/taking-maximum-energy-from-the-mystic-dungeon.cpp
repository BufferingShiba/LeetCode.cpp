
#include "leetcode/problems/taking-maximum-energy-from-the-mystic-dungeon.h"

#include "gtest/gtest.h"

namespace leetcode {
namespace problem_3147 {

class TakingMaximumEnergyFromTheMysticDungeonTest
    : public ::testing::TestWithParam<string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  TakingMaximumEnergyFromTheMysticDungeonSolution solution;
};

TEST_P(TakingMaximumEnergyFromTheMysticDungeonTest, Example1) {
  vector<int> energy = {5, 2, -10, -5, 1};
  int k = 3;
  EXPECT_EQ(solution.maximumEnergy(energy, k), 3);
}

TEST_P(TakingMaximumEnergyFromTheMysticDungeonTest, Example2) {
  vector<int> energy = {-2, -3, -1};
  int k = 2;
  EXPECT_EQ(solution.maximumEnergy(energy, k), -1);
}

TEST_P(TakingMaximumEnergyFromTheMysticDungeonTest, SelfAuthoredKEqualsOne) {
  vector<int> energy = {3, -1, 2, -4, 5};
  int k = 1;
  // 起点 index 4 => 5；各后缀和：
  // dp[4]=5, dp[3]=-4+5=1, dp[2]=2+1=3, dp[1]=-1+3=2, dp[0]=3+2=5
  EXPECT_EQ(solution.maximumEnergy(energy, k), 5);
}

TEST_P(TakingMaximumEnergyFromTheMysticDungeonTest, SelfAuthoredAllNegative) {
  vector<int> energy = {-5, -2, -8, -1, -3};
  int k = 2;
  // 同余类0: i=0 -> -5 + (-3) = -8; i=2 -> -8 + (-3) = -11; i=4 -> -3
  // 同余类1: i=1 -> -2; i=3 -> -1
  // 最大值 = -1
  EXPECT_EQ(solution.maximumEnergy(energy, k), -1);
}

TEST_P(TakingMaximumEnergyFromTheMysticDungeonTest, SelfAuthoredShortTailChoice) {
  vector<int> energy = {7, 8, 9};
  int k = 2;
  // 同余类0: i=0 -> 7+9=16; i=2 -> 9
  // 同余类1: i=1 -> 8
  EXPECT_EQ(solution.maximumEnergy(energy, k), 16);
}

INSTANTIATE_TEST_SUITE_P(
    LeetCode, TakingMaximumEnergyFromTheMysticDungeonTest,
    ::testing::ValuesIn(TakingMaximumEnergyFromTheMysticDungeonSolution()
                            .getStrategyNames()));

}  // namespace problem_3147
}  // namespace leetcode
