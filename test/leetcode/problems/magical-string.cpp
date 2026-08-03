#include "leetcode/problems/magical-string.h"

#include "gtest/gtest.h"

namespace leetcode {
namespace problem_481 {

class MagicalStringTest : public ::testing::TestWithParam<string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  MagicalStringSolution solution;
};

INSTANTIATE_TEST_SUITE_P(
    LeetCode, MagicalStringTest,
    ::testing::ValuesIn(MagicalStringSolution().getStrategyNames()));

// ===== Official Example 1 (from LeetCode) =====
// Input:  n = 6
// Output: 3
TEST_P(MagicalStringTest, OfficialExample1) {
  EXPECT_EQ(3, solution.magicalString(6));
}

// ===== Official Example 2 (from LeetCode) =====
// Input:  n = 1
// Output: 1
TEST_P(MagicalStringTest, OfficialExample2) {
  EXPECT_EQ(1, solution.magicalString(1));
}

}  // namespace problem_481
}  // namespace leetcode
