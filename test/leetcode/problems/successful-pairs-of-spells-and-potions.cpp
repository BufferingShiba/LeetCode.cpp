#include "leetcode/problems/successful-pairs-of-spells-and-potions.h"

#include "gtest/gtest.h"

namespace leetcode {
namespace problem_2300 {

class SuccessfulPairsOfSpellsAndPotionsTest : public ::testing::TestWithParam<string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  SuccessfulPairsOfSpellsAndPotionsSolution solution;
};

// ===== Official Example 1 (from LeetCode) =====
// Input:  spells = [5,1,3], potions = [1,2,3,4,5], success = 7
// Output: [4,0,3]
TEST_P(SuccessfulPairsOfSpellsAndPotionsTest, OfficialExample1) {
  vector<int> spells = {5, 1, 3};
  vector<int> potions = {1, 2, 3, 4, 5};
  long long success = 7LL;
  vector<int> expected = {4, 0, 3};
  vector<int> result = solution.successfulPairs(spells, potions, success);
  EXPECT_EQ(expected, result);
}

// ===== Official Example 2 (from LeetCode) =====
// Input:  spells = [3,1,2], potions = [8,5,8], success = 16
// Output: [2,0,2]
TEST_P(SuccessfulPairsOfSpellsAndPotionsTest, OfficialExample2) {
  vector<int> spells = {3, 1, 2};
  vector<int> potions = {8, 5, 8};
  long long success = 16LL;
  vector<int> expected = {2, 0, 2};
  vector<int> result = solution.successfulPairs(spells, potions, success);
  EXPECT_EQ(expected, result);
}

// ===== SelfAuthored: Single potion edge =====
// spells = [4,2], potions = [3], success = 10
// 4*3=12>=10 success; 2*3=6<10 fail -> [1,0]
TEST_P(SuccessfulPairsOfSpellsAndPotionsTest, SelfAuthoredSinglePotion) {
  vector<int> spells = {4, 2};
  vector<int> potions = {3};
  long long success = 10LL;
  vector<int> expected = {1, 0};
  vector<int> result = solution.successfulPairs(spells, potions, success);
  EXPECT_EQ(expected, result);
}

INSTANTIATE_TEST_SUITE_P(
    LeetCode, SuccessfulPairsOfSpellsAndPotionsTest,
    ::testing::ValuesIn(SuccessfulPairsOfSpellsAndPotionsSolution().getStrategyNames()));

}  // namespace problem_2300
}  // namespace leetcode
