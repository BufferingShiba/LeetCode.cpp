#include "leetcode/problems/utf-8-validation.h"

#include "gtest/gtest.h"

namespace leetcode {
namespace problem_393 {

class Utf8ValidationTest : public ::testing::TestWithParam<string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  Utf8ValidationSolution solution;
};

// ===== Official Example 1 (from LeetCode) =====
// Input:  data = [197,130,1]
// Output: true
TEST_P(Utf8ValidationTest, OfficialExample1) {
  std::vector<int> data = {197, 130, 1};
  bool result = solution.validUtf8(data);
  EXPECT_EQ(true, result);
}

// ===== Official Example 2 (from LeetCode) =====
// Input:  data = [235,140,4]
// Output: false
TEST_P(Utf8ValidationTest, OfficialExample2) {
  std::vector<int> data = {235, 140, 4};
  bool result = solution.validUtf8(data);
  EXPECT_EQ(false, result);
}


INSTANTIATE_TEST_SUITE_P(
    LeetCode, Utf8ValidationTest,
    ::testing::ValuesIn(Utf8ValidationSolution().getStrategyNames()));

}  // namespace problem_393
}  // namespace leetcode
