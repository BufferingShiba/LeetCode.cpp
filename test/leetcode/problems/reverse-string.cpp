#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/reverse-string.h"

namespace leetcode {
namespace problem_344 {
namespace {

void Reverse(std::vector<char>& s) {
  static ReverseStringSolution solution;
  solution.reverseString(s);
}

}  // namespace

class ReverseStringTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  ReverseStringSolution solution_;
};

TEST_P(ReverseStringTest, Example1) {
  std::vector<char> s = {'h', 'e', 'l', 'l', 'o'};
  std::vector<char> expected = {'o', 'l', 'l', 'e', 'h'};
  solution_.reverseString(s);
  EXPECT_EQ(s, expected);
}

TEST_P(ReverseStringTest, Example2) {
  std::vector<char> s = {'H', 'a', 'n', 'n', 'a', 'h'};
  std::vector<char> expected = {'h', 'a', 'n', 'n', 'a', 'H'};
  solution_.reverseString(s);
  EXPECT_EQ(s, expected);
}

TEST_P(ReverseStringTest, SelfAuthoredSingleChar) {
  std::vector<char> s = {'A'};
  std::vector<char> expected = {'A'};
  solution_.reverseString(s);
  EXPECT_EQ(s, expected);
}

TEST_P(ReverseStringTest, SelfAuthoredTwoChars) {
  std::vector<char> s = {'a', 'b'};
  std::vector<char> expected = {'b', 'a'};
  solution_.reverseString(s);
  EXPECT_EQ(s, expected);
}

INSTANTIATE_TEST_SUITE_P(
    ReverseStringTestSuite, ReverseStringTest,
    ::testing::ValuesIn(ReverseStringSolution().getStrategyNames()));

}  // namespace problem_344
}  // namespace leetcode
