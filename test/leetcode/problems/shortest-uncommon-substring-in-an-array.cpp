#include "leetcode/problems/shortest-uncommon-substring-in-an-array.h"

#include "gtest/gtest.h"

namespace leetcode {
namespace problem_3076 {

class ShortestUncommonSubstringInAnArrayTest : public ::testing::TestWithParam<string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  ShortestUncommonSubstringInAnArraySolution solution;
};

// ===== Official Example 1 (from LeetCode) =====
// Input:  arr = ["cab","ad","bad","c"]
// Output: ["ab","","ba",""]
TEST_P(ShortestUncommonSubstringInAnArrayTest, OfficialExample1) {
  vector<string> arr = {"cab", "ad", "bad", "c"};
  vector<string> expected = {"ab", "", "ba", ""};
  EXPECT_EQ(expected, solution.shortestSubstrings(arr));
}

// ===== Official Example 2 (from LeetCode) =====
// Input:  arr = ["abc","bcd","abcd"]
// Output: ["","","abcd"]
TEST_P(ShortestUncommonSubstringInAnArrayTest, OfficialExample2) {
  vector<string> arr = {"abc", "bcd", "abcd"};
  vector<string> expected = {"", "", "abcd"};
  EXPECT_EQ(expected, solution.shortestSubstrings(arr));
}


INSTANTIATE_TEST_SUITE_P(
    LeetCode, ShortestUncommonSubstringInAnArrayTest,
    ::testing::ValuesIn(ShortestUncommonSubstringInAnArraySolution().getStrategyNames()));

}  // namespace problem_3076
}  // namespace leetcode
