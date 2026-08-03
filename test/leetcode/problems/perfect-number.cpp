#include "leetcode/problems/perfect-number.h"

#include "gtest/gtest.h"

namespace leetcode {
namespace problem_507 {

class PerfectNumberTest : public ::testing::TestWithParam<string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  PerfectNumberSolution solution;
};

TEST_P(PerfectNumberTest, Example1) {
  bool result = solution.checkPerfectNumber(28);
  EXPECT_EQ(true, result);
}

// ===== Official Example 2 (from LeetCode) =====
// Input:  num = 7
// Output: false
TEST_P(PerfectNumberTest, OfficialExample2) {
  bool result = solution.checkPerfectNumber(7);
  EXPECT_EQ(false, result);
}

// Edge case: num = 1 (smallest), not a perfect number
TEST_P(PerfectNumberTest, EdgeCaseOne) {
  bool result = solution.checkPerfectNumber(1);
  EXPECT_EQ(false, result);
}

INSTANTIATE_TEST_SUITE_P(
    LeetCode, PerfectNumberTest,
    ::testing::ValuesIn(PerfectNumberSolution().getStrategyNames()));

}  // namespace problem_507
}  // namespace leetcode
