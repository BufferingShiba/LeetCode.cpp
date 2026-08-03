#include "leetcode/problems/shuffle-string.h"

#include <gtest/gtest.h>

#include <string>
#include <vector>

namespace leetcode::problem_1528 {

class ShuffleStringTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  ShuffleStringSolution solution_;
};

TEST_P(ShuffleStringTest, Example1) {
  std::string s = "codeleet";
  std::vector<int> indices = {4, 5, 6, 7, 0, 2, 1, 3};
  EXPECT_EQ("leetcode", solution_.restoreString(s, indices));
}

TEST_P(ShuffleStringTest, Example2) {
  std::string s = "abc";
  std::vector<int> indices = {0, 1, 2};
  EXPECT_EQ("abc", solution_.restoreString(s, indices));
}

TEST_P(ShuffleStringTest, SelfAuthoredReverseOrder) {
  std::string s = "abcde";
  std::vector<int> indices = {4, 3, 2, 1, 0};
  EXPECT_EQ("edcba", solution_.restoreString(s, indices));
}

INSTANTIATE_TEST_SUITE_P(
    ShuffleStringTestCases, ShuffleStringTest,
    ::testing::ValuesIn(ShuffleStringSolution().getStrategyNames()));

}  // namespace leetcode::problem_1528
