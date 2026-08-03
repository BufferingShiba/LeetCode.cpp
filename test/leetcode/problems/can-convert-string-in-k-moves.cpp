#include "leetcode/problems/can-convert-string-in-k-moves.h"

#include "gtest/gtest.h"

namespace leetcode {
namespace problem_1540 {

class CanConvertStringInKMovesTest : public ::testing::TestWithParam<string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  CanConvertStringInKMovesSolution solution;
};

// ===== Official Example 1 (from LeetCode) =====
// Input:  s = "input", t = "ouput", k = 9
// Output: true
TEST_P(CanConvertStringInKMovesTest, OfficialExample1) {
  EXPECT_EQ(true, solution.canConvertString("input", "ouput", 9));
}

// ===== Official Example 2 (from LeetCode) =====
// Input:  s = "abc", t = "bcd", k = 10
// Output: false
TEST_P(CanConvertStringInKMovesTest, OfficialExample2) {
  EXPECT_EQ(false, solution.canConvertString("abc", "bcd", 10));
}

// ===== Official Example 3 (from LeetCode) =====
// Input:  s = "aab", t = "bbb", k = 27
// Output: true
TEST_P(CanConvertStringInKMovesTest, OfficialExample3) {
  EXPECT_EQ(true, solution.canConvertString("aab", "bbb", 27));
}


INSTANTIATE_TEST_SUITE_P(
    LeetCode, CanConvertStringInKMovesTest,
    ::testing::ValuesIn(CanConvertStringInKMovesSolution().getStrategyNames()));

}  // namespace problem_1540
}  // namespace leetcode
