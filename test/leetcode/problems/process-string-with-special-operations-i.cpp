#include "leetcode/problems/process-string-with-special-operations-i.h"

#include "gtest/gtest.h"

namespace leetcode {
namespace problem_3612 {

class ProcessStringWithSpecialOperationsITest : public ::testing::TestWithParam<string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  ProcessStringWithSpecialOperationsISolution solution;
};

// ===== Official Example 1 (from LeetCode) =====
// Input:  s = "a#b%*"
// Output: "ba"
TEST_P(ProcessStringWithSpecialOperationsITest, OfficialExample1) {
  std::string result = solution.processStr("a#b%*");
  EXPECT_EQ(result, "ba");
}

// ===== Official Example 2 (from LeetCode) =====
// Input:  s = "z*#"
// Output: ""
TEST_P(ProcessStringWithSpecialOperationsITest, OfficialExample2) {
  std::string result = solution.processStr("z*#");
  EXPECT_EQ(result, "");
}


INSTANTIATE_TEST_SUITE_P(
    LeetCode, ProcessStringWithSpecialOperationsITest,
    ::testing::ValuesIn(ProcessStringWithSpecialOperationsISolution().getStrategyNames()));

}  // namespace problem_3612
}  // namespace leetcode
