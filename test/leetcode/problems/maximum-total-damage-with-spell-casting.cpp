#include <gtest/gtest.h>

#include "leetcode/problems/maximum-total-damage-with-spell-casting.h"

namespace leetcode {
namespace problem_3186 {

class MaximumTotalDamageWithSpellCastingTest : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override {
    solution_.setStrategy(GetParam());
  }

  MaximumTotalDamageWithSpellCastingSolution solution_;
};

TEST_P(MaximumTotalDamageWithSpellCastingTest, Example1) {
  std::vector<int> power = {1, 1, 3, 4};
  EXPECT_EQ(solution_.maximumTotalDamage(power), 6);
}

TEST_P(MaximumTotalDamageWithSpellCastingTest, Example2) {
  std::vector<int> power = {7, 1, 6, 6};
  EXPECT_EQ(solution_.maximumTotalDamage(power), 13);
}

TEST_P(MaximumTotalDamageWithSpellCastingTest, SelfAuthoredSingleElement) {
  std::vector<int> power = {10};
  EXPECT_EQ(solution_.maximumTotalDamage(power), 10);
}

TEST_P(MaximumTotalDamageWithSpellCastingTest, SelfAuthoredAllSameValue) {
  std::vector<int> power = {5, 5, 5};
  EXPECT_EQ(solution_.maximumTotalDamage(power), 15);
}

TEST_P(MaximumTotalDamageWithSpellCastingTest, SelfAuthoredCompatibleAll) {
  // All values differ by >= 3, can take all
  std::vector<int> power = {1, 4, 7, 10};
  EXPECT_EQ(solution_.maximumTotalDamage(power), 22);
}

TEST_P(MaximumTotalDamageWithSpellCastingTest, SelfAuthoredIncompatibleSequence) {
  // Consecutive values: cannot take adjacent
  std::vector<int> power = {1, 2, 3, 4, 5};
  // Best is taking 5 + 2 = 7 or 4 + 1 = 5 or 5+1=6?
  // Actually: can't take values diff <= 2.
  // Values: 1(1), 2(2), 3(3), 4(4), 5(5)
  // Compatible pairs: 1+4=5, 1+5=6, 2+5=7, 3 alone=3
  // Best: 2+5=7
  EXPECT_EQ(solution_.maximumTotalDamage(power), 7);
}

TEST_P(MaximumTotalDamageWithSpellCastingTest, SelfAuthoredLargeGap) {
  std::vector<int> power = {1, 1000000000};
  EXPECT_EQ(solution_.maximumTotalDamage(power), 1000000001LL);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    MaximumTotalDamageWithSpellCastingTest,
    testing::ValuesIn(MaximumTotalDamageWithSpellCastingSolution().getStrategyNames()));

}  // namespace problem_3186
}  // namespace leetcode
