
#include "leetcode/problems/find-the-minimum-amount-of-time-to-brew-potions.h"

#include "gtest/gtest.h"

namespace leetcode {
namespace problem_3494 {

class FindTheMinimumAmountOfTimeToBrewPotionsTest
    : public ::testing::TestWithParam<string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  FindTheMinimumAmountOfTimeToBrewPotionsSolution solution;
};

TEST_P(FindTheMinimumAmountOfTimeToBrewPotionsTest, Example1) {
  vector<int> skill = {1, 5, 2, 4};
  vector<int> mana = {5, 1, 4, 2};
  EXPECT_EQ(110LL, solution.minTime(skill, mana));
}

TEST_P(FindTheMinimumAmountOfTimeToBrewPotionsTest, Example2) {
  vector<int> skill = {1, 1, 1};
  vector<int> mana = {1, 1, 1};
  EXPECT_EQ(5LL, solution.minTime(skill, mana));
}

TEST_P(FindTheMinimumAmountOfTimeToBrewPotionsTest, Example3) {
  vector<int> skill = {1, 2, 3, 4};
  vector<int> mana = {1, 2};
  EXPECT_EQ(21LL, solution.minTime(skill, mana));
}

TEST_P(FindTheMinimumAmountOfTimeToBrewPotionsTest, SelfAuthoredSingleWizardSinglePotion) {
  vector<int> skill = {7};
  vector<int> mana = {3};
  EXPECT_EQ(21LL, solution.minTime(skill, mana));
}

TEST_P(FindTheMinimumAmountOfTimeToBrewPotionsTest, SelfAuthoredSingleWizardMultiplePotions) {
  vector<int> skill = {2};
  vector<int> mana = {1, 3, 2};
  // 单巫师依次处理：potion0: start=0,end=2; potion1: start=2,end=8; potion2: start=8,end=12
  EXPECT_EQ(12LL, solution.minTime(skill, mana));
}

INSTANTIATE_TEST_SUITE_P(
    LeetCode, FindTheMinimumAmountOfTimeToBrewPotionsTest,
    ::testing::ValuesIn(
        FindTheMinimumAmountOfTimeToBrewPotionsSolution().getStrategyNames()));

}  // namespace problem_3494
}  // namespace leetcode
