#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/reverse-string-prefix.h"

namespace leetcode {
namespace problem_3794 {

namespace {

std::vector<std::string> GetStrategyNames() {
  return ReverseStringPrefix().getStrategyNames();
}

}  // namespace

class ReverseStringPrefixTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  ReverseStringPrefix solution;
};

TEST_P(ReverseStringPrefixTest, Example1) {
  EXPECT_EQ("bacd", solution.reversePrefix("abcd", 2));
}

TEST_P(ReverseStringPrefixTest, Example2) {
  EXPECT_EQ("zyx", solution.reversePrefix("xyz", 3));
}

TEST_P(ReverseStringPrefixTest, Example3) {
  EXPECT_EQ("hey", solution.reversePrefix("hey", 1));
}

TEST_P(ReverseStringPrefixTest, SelfAuthored_kEqualsLength) {
  EXPECT_EQ("cba", solution.reversePrefix("abc", 3));
}

TEST_P(ReverseStringPrefixTest, SelfAuthored_kIsOne) {
  EXPECT_EQ("abcde", solution.reversePrefix("abcde", 1));
}

TEST_P(ReverseStringPrefixTest, SelfAuthored_middleReverse) {
  EXPECT_EQ("edcbafghi", solution.reversePrefix("abcdefghi", 5));
}

INSTANTIATE_TEST_SUITE_P(
    ReverseStringPrefixTestSuite, ReverseStringPrefixTest,
    ::testing::ValuesIn(GetStrategyNames()));

}  // namespace problem_3794
}  // namespace leetcode
