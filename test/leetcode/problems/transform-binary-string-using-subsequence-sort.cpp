#include <gtest/gtest.h>

#include "leetcode/problems/transform-binary-string-using-subsequence-sort.h"

namespace leetcode {
namespace problem_3998 {

class TransformBinaryStringUsingSubsequenceSortTest
    : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }
  TransformBinaryStringUsingSubsequenceSortSolution solution_;
};

TEST_P(TransformBinaryStringUsingSubsequenceSortTest, Example1) {
  std::string s = "101";
  std::vector<std::string> strs = {"1?1", "0?1", "0?0"};
  std::vector<bool> expected = {true, true, false};
  EXPECT_EQ(solution_.transformStr(s, strs), expected);
}

TEST_P(TransformBinaryStringUsingSubsequenceSortTest, Example2) {
  std::string s = "1100";
  std::vector<std::string> strs = {"0011", "11?1", "1?1?"};
  std::vector<bool> expected = {true, false, true};
  EXPECT_EQ(solution_.transformStr(s, strs), expected);
}

TEST_P(TransformBinaryStringUsingSubsequenceSortTest, Example3) {
  std::string s = "1010";
  std::vector<std::string> strs = {"0011"};
  std::vector<bool> expected = {true};
  EXPECT_EQ(solution_.transformStr(s, strs), expected);
}

TEST_P(TransformBinaryStringUsingSubsequenceSortTest, SelfAuthoredSingleChar) {
  std::string s = "1";
  std::vector<std::string> strs = {"?", "0", "1"};
  // s has 0 zeros, need0 = 0
  // "?": treat as 1 → "1", pref0_t=[0], pref0_s=[0] ✓
  // "0": fixed0=1 > cnt0_s=0 → false
  // "1": fixed0=0, pref0_t=[0]=pref0_s ✓
  std::vector<bool> expected = {true, false, true};
  EXPECT_EQ(solution_.transformStr(s, strs), expected);
}

TEST_P(TransformBinaryStringUsingSubsequenceSortTest, SelfAuthoredAllQuestions) {
  std::string s = "0101";
  // s has two 0s
  std::vector<std::string> strs = {"????"};
  // need0 = 2, earliest: "0011"
  // pref0_s = [1,1,2,2]
  // pref0_t = [1,2,2,2]
  // i=0:1≥1 ✓, i=1:2≥1 ✓, i=2:2≥2 ✓, i=3:2=2 ✓ → true
  std::vector<bool> expected = {true};
  EXPECT_EQ(solution_.transformStr(s, strs), expected);
}

TEST_P(TransformBinaryStringUsingSubsequenceSortTest, SelfAuthoredNotEnoughZeros) {
  std::string s = "000";
  std::vector<std::string> strs = {"1??"};
  // cnt0_s = 3, fixed0 = 0, q = 2, need0 = 3 > 2 → false
  std::vector<bool> expected = {false};
  EXPECT_EQ(solution_.transformStr(s, strs), expected);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies, TransformBinaryStringUsingSubsequenceSortTest,
    testing::ValuesIn(
        TransformBinaryStringUsingSubsequenceSortSolution().getStrategyNames()));

}  // namespace problem_3998
}  // namespace leetcode
