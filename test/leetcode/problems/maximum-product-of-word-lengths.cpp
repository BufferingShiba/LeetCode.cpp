#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/maximum-product-of-word-lengths.h"

namespace leetcode {
namespace problem_318 {
namespace {

class MaximumProductOfWordLengthsTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  MaximumProductOfWordLengthsSolution solution_;
};

TEST_P(MaximumProductOfWordLengthsTest, Example1) {
  std::vector<std::string> words = {"abcw", "baz", "foo", "bar", "xtfn",
                                    "abcdef"};
  EXPECT_EQ(16, solution_.maxProduct(words));
}

TEST_P(MaximumProductOfWordLengthsTest, Example2) {
  std::vector<std::string> words = {"a", "ab", "abc", "d", "cd", "bcd",
                                    "abcd"};
  EXPECT_EQ(4, solution_.maxProduct(words));
}

TEST_P(MaximumProductOfWordLengthsTest, Example3) {
  std::vector<std::string> words = {"a", "aa", "aaa", "aaaa"};
  EXPECT_EQ(0, solution_.maxProduct(words));
}

TEST_P(MaximumProductOfWordLengthsTest, SelfAuthoredSingleLetterShared) {
  // "ab" and "cd" share no letters -> 2*2=4; "ab" and "ac" share 'a'.
  std::vector<std::string> words = {"ab", "cd", "ac"};
  EXPECT_EQ(4, solution_.maxProduct(words));
}

TEST_P(MaximumProductOfWordLengthsTest, SelfAuthoredAllPairsShareLetter) {
  // Every word contains 'x', so no pair qualifies.
  std::vector<std::string> words = {"ax", "xab", "xc"};
  EXPECT_EQ(0, solution_.maxProduct(words));
}

INSTANTIATE_TEST_SUITE_P(
    MaximumProductOfWordLengthsTestCases, MaximumProductOfWordLengthsTest,
    ::testing::ValuesIn(
        MaximumProductOfWordLengthsSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_318
}  // namespace leetcode
